// Copyright 2017 Qi Wang
// Date: 2017-09-16
// Case 1:
//   insert("cloud", 4)
//   sum("c") => return 4
//   insert("cow", 2)
//   sum("c") => return 6
class MapSum {
 public:
  void insert(string key, int val) {
    s_to_i_map_[key] = val;
  }
  
  int sum(string prefix) {
    int result = 0;
    for(auto it = s_to_i_map_.lower_bound(prefix);
        it != s_to_i_map_.end() && Contains(it->first, prefix); ++it) {
      result += it->second;
    }
    return result;
  }

 private:
  bool Contains(const string& s, const string& prefix) const {
    for (int i = 0; i < prefix.size(); ++i) {
      if (s[i] != prefix[i]) return false;
    }
    return true;
  }

  map<string, int> s_to_i_map_;
};
