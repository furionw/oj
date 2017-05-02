// Copyright 2017 Qi Wang
// Method 2
// Refer to: https://discuss.leetcode.com/topic/86545/c-9ms-12-lines
// Date: 2017-05-02
class Solution {
 public:
  string splitLoopedString(vector<string>& strs) {
    string result;
    for (const auto& str : strs) {
      string temp = str;
      reverse(temp.begin(), temp.end());
      result += max(str, temp);
    }
    auto origin = result;
    for (size_t i = 0, pos = 0; i < strs.size(); pos += strs[i++].size()) {
      string s1 = strs[i], s2 = strs[i],
          body = origin.substr(pos + s1.size()) + origin.substr(0, pos);
      reverse(s2.begin(), s2.end());
      for (size_t j = 0; j < s1.size(); ++j) {
        // These two "if" do boost up the process from 26ms to 12ms
        if (s1[j] >= result[0])
          result = max(result, s1.substr(j) + body + s1.substr(0, j));
        if (s2[j] >= result[0])
          result = max(result, s2.substr(j) + body + s2.substr(0, j));
      }
    }
    return result;
  }
};

// Method 1
// Time: about 26ms
// Date: 2017-05-02
class Solution {
 public:
  string splitLoopedString(vector<string>& strs) {
    for (auto& str : strs) {
      string temp = str;
      reverse(temp.begin(), temp.end());
      if (temp > str) str = temp;
    }
    string result = accumulate(strs.begin(), strs.end(), string());
    for (size_t i = 0; i < strs.size(); ++i) {
      for (size_t len = 1; len <= strs[i].size(); ++len) {
        string temp = strs[i].substr(len) +
            accumulate(strs.begin() + i + 1, strs.end(), string()) +
            accumulate(strs.begin(), strs.begin() + i, string()) +
            strs[i].substr(0, len);
        result = max(result, temp);
      }
      reverse(strs[i].begin(), strs[i].end());
      for (size_t len = 1; len <= strs[i].size(); ++len) {
        string temp = strs[i].substr(len) +
            accumulate(strs.begin() + i + 1, strs.end(), string()) +
            accumulate(strs.begin(), strs.begin() + i, string()) +
            strs[i].substr(0, len);
        result = max(result, temp);
      }
      reverse(strs[i].begin(), strs[i].end());
    }
    return result;
  }
};
