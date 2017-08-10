// Copyright 2017 Qi Wang
// Date: 2017-08-09
class LFUCache {
 public:
  LFUCache(int capacity) : CAPACITY(capacity) {}
  
  int get(int key) {
    if (CAPACITY == 0) return -1;
    if (key_to_cache_map_.find(key) == key_to_cache_map_.end()) {
      return -1;
    } else {
      auto list_itr = key_to_list_map_[key];
      auto cache_itr = key_to_cache_map_[key];
      int freq = list_itr->freq + 1;
      auto next = list_itr;
      ++next;
      if (next != lists_.end() && next->freq == freq) {
        key_to_list_map_[key] = next;
        next->caches.splice(next->caches.begin(), list_itr->caches, cache_itr);
      } else {
        key_to_list_map_[key] = lists_.emplace(next, freq);
        auto& target_list = key_to_list_map_[key]->caches;
        target_list.splice(target_list.begin(), list_itr->caches, cache_itr);
      }
      if (list_itr->caches.empty()) {
        lists_.erase(list_itr);
      }
      return cache_itr->value;
    }
  }
   
  void put(int key, int value) {
    if (CAPACITY == 0) return;
    if (key_to_cache_map_.find(key) == key_to_cache_map_.end()) {
      if (sz_ + 1 > CAPACITY) {
        int key_to_remove = lists_.front().caches.back().key;
        lists_.front().caches.pop_back();
        key_to_cache_map_.erase(key_to_remove);
        key_to_list_map_.erase(key_to_remove);
        if (lists_.front().caches.empty()) {
          lists_.pop_front();
        }
      } else {
        ++sz_;
      }
      key_to_list_map_[key] = lists_.empty() || lists_.begin()->freq != 1
          ? lists_.emplace(lists_.begin(), 1)
          : lists_.begin();
      auto& target_list = lists_.begin()->caches;
      key_to_cache_map_[key] = target_list.emplace(target_list.begin(), key,
                                                   value);
    } else {
      get(key);
      key_to_cache_map_[key]->value = value;
    } 
  }
 
 private:
  struct Cache {
    Cache(int k, int v) : key(k), value(v) {}
    int key;
    int value;
  };
 
  struct CacheList {
    CacheList(int f) : freq(f) {}
    int freq = 0;
    list<Cache> caches;
  };
 
  const int CAPACITY;
  int sz_ = 0;
  list<CacheList> lists_;
  unordered_map<int, list<CacheList>::iterator> key_to_list_map_;
  unordered_map<int, list<Cache>::iterator> key_to_cache_map_;
};

// Refer to: http://bookshadow.com/weblog/2016/11/22/leetcode-lfu-cache/
// Date: 2016-11-24
// Here we assume freq is always less than INT_MAX
class LFUCache {
 private:
  struct Block {
    Block() {}
    Block(int k, int v, int f) : key(k), value(v), freq(f) {}
    int key;
    int value;
    int freq;
  };

 public:
  LFUCache(int capacity) : capacity_(capacity) {}
    
  int get(int key) {
    if (!capacity_) return -1;
    auto it = blkMap_.find(key);
    // Found
    if (it != blkMap_.end()) {
      return incFreq(it->second)->value;
    // No Found
    } else {
      return -1;
    }
  }
    
  void set(int key, int value) {
    if (!capacity_) return;
    auto it = blkMap_.find(key);
    // Found
    if (it != blkMap_.end()) {
      incFreq(it->second)->value = value;
    // No Found
    } else {
      // The cache is full
      if (sz_ == capacity_) {
        const auto& blk = blkTbl_.front().back();
        int key = blk.key;
        int freq = blk.freq;
        // blk reference is invalidated since pop_back()
        blkTbl_.front().pop_back();
        blkMap_.erase(key);
        if (blkTbl_.front().empty()) {
          freqMap_.erase(freq);
          blkTbl_.pop_front();
        }
      } else {
        ++sz_;
      }
      if (blkTbl_.empty() || blkTbl_.front().front().freq > 1) {
        freqMap_[1] = blkTbl_.emplace(blkTbl_.begin());
      }
      blkMap_[key] = freqMap_[1]->emplace(freqMap_[1]->begin(), key, value, 1);
    }
  }

 private:
  list<Block>::iterator& incFreq(list<Block>::iterator& it) {
    int& freq = it->freq;
    auto blockListIt = freqMap_[freq];
    auto nextBlockListIt = blockListIt;
    ++nextBlockListIt;
    if (nextBlockListIt == blkTbl_.end()
        || nextBlockListIt->front().freq != freq + 1) {
      freqMap_[freq + 1] = blkTbl_.emplace(nextBlockListIt);
      nextBlockListIt = freqMap_[freq + 1];
    }
    // splice
    nextBlockListIt->splice(nextBlockListIt->begin(), *blockListIt, it);
    // remove
    if (blockListIt->empty()) {
      blkTbl_.erase(blockListIt);
      freqMap_.erase(freq);
    }
    ++freq;  // inc its frequency by reference
    return it;  // return it back thus set() could modify its value
  }

  list<list<Block>> blkTbl_;
  int sz_ = 0;
  int capacity_;
  // freq -> BlockList
  unordered_map<int, list<list<Block>>::iterator> freqMap_;
  // key -> Block
  unordered_map<int, list<Block>::iterator> blkMap_;
};
