// Copyright 2016 Qi Wang
// Date: 2016-11-02
class Solution {
 public:
  vector<string> summaryRanges(vector<int>& nums) {
    vector<string> res;
    if (nums.empty()) return res;
    int beginNum = nums.front(), len = 1;
    for (auto it = nums.begin() + 1; it != nums.end(); ++it)
      if (*it == beginNum + len) {
        ++len;
      } else {
        res.emplace_back(to_string(beginNum) + 
            (len != 1 ? "->" + to_string(beginNum + len - 1) : ""));
        beginNum = *it;
        len = 1;
      }
    res.emplace_back(to_string(beginNum) + 
        (len != 1 ? "->" + to_string(beginNum + len - 1) : ""));
    return res;
  }
};

// Date: 2016-10-05
class Solution {
 public:
  vector<string> summaryRanges(vector<int>& nums) {
    vector<string> res;
    if (nums.empty()) return res;
    int pre = nums.front();
    string elem = int_to_string(pre);
    int cnt = 1;
    for (auto it = nums.begin() + 1; it != nums.end(); ++it) {
      if (*it == pre + 1) {
        ++pre;
        ++cnt;
      } else {
        res.push_back(elem + (cnt > 1 ? "->" + int_to_string(pre) : ""));
        pre = *it;
        elem = int_to_string(pre);
        cnt = 1;
      }
    }
    res.push_back(elem + (cnt > 1 ? "->" + int_to_string(pre) : ""));
    return res;
  }

 private:
  inline string int_to_string(int num) const {
    stringstream ss;
    ss << num;
    string str;
    ss >> str;
    return str;
  }
};
