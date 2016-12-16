// Copyright 2016 Qi Wang
// 4th time
// 66ms, beats 89% cpp solutions
// Date: 2016-12-16
class LRUCache {
 private:
  struct Block {
    Block(int k, int v) : key(k), val(v) {}
    int key, val;
  };

 public:
  LRUCache(int capacity) : CAPACITY_(capacity) {}

  int get(int key) {
    auto it = kToBlk_.find(key);
    if (it == kToBlk_.end()) return -1;
    blks_.splice(blks_.begin(), blks_, it->second);
    return blks_.front().val;
  }

  void set(int key, int value) {
    auto it = kToBlk_.find(key);
    // exists
    if (it != kToBlk_.end()) {
      blks_.splice(blks_.begin(), blks_, it->second);
      blks_.front().val = value;
    // no exists
    } else {
      if (blks_.size() == CAPACITY_) {
        kToBlk_.erase(blks_.back().key);
        blks_.pop_back();
      }
      kToBlk_[key] = blks_.emplace(blks_.begin(), key, value);
    }
  }

 private:
  // Qi makes his progress by using "const" declarator here, comparing to the
  // previous solutions
  const int CAPACITY_;
  list<Block> blks_;
  unordered_map<int, list<Block>::iterator> kToBlk_;
};

// 3rd time
// Introduce splice() accoding to Ming Lin's advice
// Date: 2016-11-24
class LRUCache {
 private:
  struct Block {
    Block(int k, int v) : key(k), value(v) {}
    int key;
    int value;
  };

 public:
  LRUCache(int c) : capacity_(c) {}
    
  int get(int key) {
    auto it = blockM_.find(key);
    if (it != blockM_.end()) {
      // Move node to the head, meaning it's the most recently used
      blockL_.splice(blockL_.begin(), blockL_, it->second);
      // "it" remains its validity after splicing. More detail could be fetched
      // from "Iterator Validity" -- http://www.cplusplus.com/reference/list/list/splice/
      return it->second->value;
    } else {
      return -1;
    }
  }
    
  void set(int key, int value) {
    auto it = blockM_.find(key);
    if (it != blockM_.end()) {
      blockL_.splice(blockL_.begin(), blockL_, it->second);
      // Note that we have illustrate the iterator validity before
      it->second->value = value;
    } else {
      // Remove the tail when the list's capacity is full
      if (blockL_.size() == capacity_) {
        blockM_.erase(blockL_.back().key);
        blockL_.pop_back();
      }
      blockM_[key] = blockL_.emplace(blockL_.begin(), key, value);
    }
  }

 private:
  list<Block> blockL_;
  unordered_map<int, list<Block>::iterator> blockM_;
  int capacity_;
};

// Method 1
// Date: 2016-11-23
class LRUCache {
 private:
  struct Block {
    Block(int k, int v) : key(k), value(v) {}
    int key;
    int value;
  };

 public:
  LRUCache(int c) : capacity_(c) {}
    
  int get(int key) {
    auto it = blockM_.find(key);
    if (it != blockM_.end()) {
      return moveToTail(it)->value;
    } else {
      return -1;
    }
  }
    
  void set(int key, int value) {
    auto it = blockM_.find(key);
    if (it != blockM_.end()) {
      moveToTail(it)->value = value;
    } else {
      // Remove the least recently used block when the cache's capacity is full
      if (blockL_.size() == capacity_) {
        // The LRU block is at the front of the list in this implementation
        blockM_.erase(blockL_.front().key);
        blockL_.pop_front();
      }
      blockM_[key] = blockL_.emplace(blockL_.end(), key, value);
    }
  }

 private:
  inline list<Block>::iterator& moveToTail(
      unordered_map<int, list<Block>::iterator>::iterator& it) {
    blockL_.push_back(*it->second);
    blockL_.erase(it->second);
    return it->second = --blockL_.end();
  }

  list<Block> blockL_;
  unordered_map<int, list<Block>::iterator> blockM_;
  int capacity_;
};

// Date: 2014-06
class LRUCache
{
public:
    LRUCache(int c): capacity(c) {}
    
    int get(int key) 
    {
      if (content.count(key) != 0)
      {
      LRU_update(key, content[key]->val); // is it necessary?
      return content[key]->val;
      } else
      {
        return -1;
      }
    }
    
    void set(int key, int value) 
    {
        if (content.count(key) != 0) // in map
        {
          LRU_update(key, value);
        } else if ( content.size() < capacity )
        {
          LRU_insert(key, value);
        } else
        {
          LRU_replace(key, value);
        }
    }

private:
  class Cache_node
  {
  public:
    int key;
    int val;
    Cache_node(int k, int v): key(k), val(v) {}
  };

    void LRU_update(int key, int value)
    {
    node_list.splice(node_list.begin(), node_list, content[key]);
    node_list.front().val = value; // use for set
    content[key] = node_list.begin();
    }

    void LRU_insert(int key, int value)
    {
    node_list.push_front(Cache_node(key, value));      
    content[key] = node_list.begin();
    }

    void LRU_replace(int key, int value)
    {
    content.erase( node_list.back().key );
      node_list.pop_back();
      LRU_insert(key, value);
    }

  int capacity;
  list<Cache_node> node_list;
  // Updated 2016-11-23
  unordered_map<int, list<Cache_node>::iterator> content;
  // map<int, list<Cache_node>::iterator> content;
};
