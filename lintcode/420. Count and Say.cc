// Copyright 2017 Qi Wang
// Date: 2017-10-11
// Case 1: 1 -> "1"
// Case 2: 2 -> "1" -> "11"
// Case 3: 3 -> "11" -> "21"
// Case 4: 4 -> "21" -> "1211"
class Solution {
 public:
  string countAndSay(int n) {
    string str = "1";
    for (int i = 1; i < n; ++i) {
      str = CountAndSay(str);
    }
    return str;
  }
 
 private:
  string CountAndSay(const string& str) const {
    char prev = str[0];
    int cnt = 1;
    string result;
    for (int i = 1; i < str.size(); ++i) {
      if (str[i] != prev) {
        result += to_string(cnt) + string(1, prev);
        prev = str[i];
        cnt = 1;
      } else {
        ++cnt;
      }
    }
    return result + to_string(cnt) + string(1, prev);
  }
};
