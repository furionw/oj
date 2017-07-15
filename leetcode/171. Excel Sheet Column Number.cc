// Copyright 2017 Qi Wang
// Date: 2017-07-14
// Method 2
class Solution {
 public:
  int titleToNumber(string s) {
    return accumulate(s.begin(), s.end(), 0, [](int acc, char c) {
      return 26 * acc + c - 'A' + 1;
    });
  }
};

// Date: 2017-07-14
// Method 1
class Solution {
 public:
  int titleToNumber(string s) {
    int result = 0;
    for (char c : s)
      result = 26 * result + c - 'A' + 1;
    return result;
  }
};

class Solution 
{
public:
    int titleToNumber(string s) 
    {
        int ret = 0;
        for (size_t i = 0; i < s.size(); ++ i)
        {
          ret *= 26;
          ret += (s[i] - 'A' + 1);
        }
        return ret;
    }
};