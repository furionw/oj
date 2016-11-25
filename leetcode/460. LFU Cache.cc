// Copyright 2016 Qi Wang
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
