// Copyright 2017 Qi Wang
// Date: 2017-07-01
class LogSystem {
 public:   
  void put(int id, string timestamp) {
    time_to_id_[timestamp].push_back(id);
  }
  
  vector<int> retrieve(string s, string e, string gra) {
    size_t len = g_to_len_[gra];
    s = s.substr(0, len);
    e = e.substr(0, len);
    vector<int> result;
    for (auto it = time_to_id_.lower_bound(s);
          it != time_to_id_.end() && it->first.substr(0, len) <= e; ++it) {
      for (int id : it->second)
        result.push_back(id);
    }
    return result;
  }

 private:
  map<string, list<int>> time_to_id_;
  unordered_map<string, int> g_to_len_ = {
    {"Year", 4},
    {"Month", 7},
    {"Day", 10},
    {"Hour", 13},
    {"Minute", 16},
    {"Second", 19}
  };
};
