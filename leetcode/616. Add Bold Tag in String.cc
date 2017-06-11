// Copyright 2017 Qi Wang
// Date: 2017-06-11
class Solution {
public:
  string addBoldTag(string s, vector<string>& dict) {
    if (s.empty()) return "";
    unordered_set<string> d;
    for (const auto& str : dict)
      d.insert(str);
    size_t end = 0;
    vector<bool> record(s.size(), false);
    for (int i = 0; i < s.size(); ++i) {
      for (int j = s.size(); j >= end && j > i; --j) {
        if (d.count(s.substr(i, j - i)) > 0) {
          end = j;
          fill(record.begin() + i, record.begin() + j, true);
          break;
        }
      }
    }
    string result;
    bool begin = false;
    int begin_idx = -1;
    for (int i = 0; i < s.size(); ++i) {
      if (record[i]) {
        if (!begin) {
          begin_idx = i;
          begin = true;
        }
      } else {
        if (begin) {
          begin = false;
          result += "<b>";
          result += s.substr(begin_idx, i - begin_idx) + "</b>";          
        }
        result += s[i];
      }
    }
    if (begin) {
      result += "<b>";
      result += s.substr(begin_idx) + "</b>";
    }
    return result;
  }
};
