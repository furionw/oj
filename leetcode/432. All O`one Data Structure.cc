// Copyright 2016 Qi Wang
// Date: 2016-12-16
// 2rd time
class AllOne {
  private:
  struct KeyValue {
    KeyValue(string k, int v) : key(k), val(v) {}
    string key;
    int val;
  };

 public:
  // Inserts a new key <Key> with value 1. Or increments an existing key by 1.
  void inc(string key) {
    auto it = kToKv_.find(key);
    // new key
    if (it == kToKv_.end()) {
      if (kvTbl_.empty() || kvTbl_.front().front().val != 1)
        vToKvs_[1] = kvTbl_.emplace(kvTbl_.begin());
      kToKv_[key] = vToKvs_[1]->emplace(vToKvs_[1]->begin(), key, 1);
    // existing key
    } else {
      // value of key is incremented here
      int val = it->second->val++;
      auto kvListIt = vToKvs_[val];
      auto nextKvListIt = kvListIt;
      ++nextKvListIt;
      if (nextKvListIt == kvTbl_.end() || nextKvListIt->front().val != val + 1)
        nextKvListIt = vToKvs_[val + 1] = kvTbl_.emplace(nextKvListIt);
      nextKvListIt->splice(nextKvListIt->begin(), *kvListIt, it->second);
      if (kvListIt->empty()) {
        kvTbl_.erase(kvListIt);
        vToKvs_.erase(val);
      }
    }
  }
    
  /** Decrements an existing key by 1. If Key's value is 1, 
      remove it from the data structure. */
  void dec(string key) {
    auto it = kToKv_.find(key);
    if (it == kToKv_.end()) return;
    // key’s value is decremented here
    int val = it->second->val--;
    if (val == 1) {
      kToKv_.erase(key);
      vToKvs_[1]->erase(it->second);
    } else {
      // the original list where kv reside for now
      auto kvListIt = vToKvs_.find(val)->second;
      auto preKvListIt = kvListIt;
      if (kvListIt == kvTbl_.begin()
          || (--preKvListIt)->front().val != val - 1)
        preKvListIt = vToKvs_[val - 1] = kvTbl_.emplace(kvListIt);
      preKvListIt->splice(preKvListIt->begin(), *kvListIt, it->second);
    }
    if (vToKvs_[val]->empty()) {
      kvTbl_.erase(vToKvs_[val]);
      vToKvs_.erase(val);
    }
  }

  /** Returns one of the keys with maximal value. */
  string getMaxKey() {
    return kvTbl_.empty() ? "" : kvTbl_.back().front().key;
  }

  /** Returns one of the keys with Minimal value. */
  string getMinKey() {
    return kvTbl_.empty() ? "" : kvTbl_.front().front().key;
  }

 private:
  unordered_map<int, list<list<KeyValue>>::iterator> vToKvs_;
  unordered_map<string, list<KeyValue>::iterator> kToKv_;
  list<list<KeyValue>> kvTbl_;
};

// 1st time
// Date: 2016-12-01
class AllOne {
 private:
  struct KeyValue {
    KeyValue(string k, int v) : key(k), value(v) {}
    string key;
    int value;
  };

 public:
  /** Initialize your data structure here. */
  AllOne() {}

  /** Inserts a new key <Key> with value 1. Or increments an existing key by 1. */
  void inc(string key) {
    auto it = kMap_.find(key);
    // Non exist before
    if (it == kMap_.end()) {
      if (l_.empty() || l_.front().front().value != 1)
        vMap_[1] = l_.emplace(l_.begin());
      kMap_[key] = l_.front().emplace(l_.front().begin(), key, 1);
    } else {
      auto node = it->second;
      int value = (node->value)++;
      auto vList = vMap_[value];
      auto nextVList = vList;
      ++nextVList;
      if (nextVList == l_.end() || nextVList->front().value != value + 1)
        nextVList = vMap_[value + 1] = l_.emplace(nextVList);
      nextVList->splice(nextVList->begin(), *vList, node);
      if (vList->empty()) {
        l_.erase(vList);
        vMap_.erase(value);
      }
    }
  }

  /** Decrements an existing key by 1. If Key's value is 1, remove it from the data structure. */
  void dec(string key) {
    auto it = kMap_.find(key);
    if (it == kMap_.end()) {
      cerr << "Key doesn't exist." << endl;
    } else {
      auto node = it->second;
      const int VALUE = node->value;
      auto vList = vMap_[VALUE];
      if (VALUE == 1) {
        // Remove key from vList
        vList->erase(node);
        // Remove invalid iterator from kMap_
        kMap_.erase(key);
      } else {
        // Decrement key's value
        --node->value;
        list<list<KeyValue>>::iterator preList;
        // Introduce this if-else stmt avoiding decrement the begin() iterator
        if (vList == l_.begin()) {
          preList = vMap_[VALUE - 1] = l_.emplace(vList);
        } else {
          preList = vList;
          // decrement an iterator
          --preList;
          if (preList->front().value != VALUE - 1)
            preList = vMap_[VALUE - 1] = l_.emplace(vList);
        }
        // Splice KeyValue from vList to preList
        preList->splice(preList->begin(), *vList, node);
      }
      if (vList->empty()) {
        // Remove empty list from l_
        l_.erase(vList);
        // Remove invalid iterator from vMap_
        vMap_.erase(VALUE);
      }
    }
  }

  /** Returns one of the keys with maximal value. */
  string getMaxKey() {
    return l_.empty() ? "" : l_.back().front().key;
  }

  /** Returns one of the keys with Minimal value. */
  string getMinKey() {
    return l_.empty() ? "" : l_.front().front().key;
  }

 private:
  unordered_map<int, list<list<KeyValue>>::iterator> vMap_;
  unordered_map<string, list<KeyValue>::iterator> kMap_;
  list<list<KeyValue>> l_;
};
