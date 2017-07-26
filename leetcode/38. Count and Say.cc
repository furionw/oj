// Copyright 2017 Qi Wang
// Date: 2017-07-25
class Solution {
 public:
  string countAndSay(int n) {
    return CountAndSay("1", n);
  }

 private:
  string CountAndSay(const string& str, int n) const {
    if (n == 1) {
      return str;
    }
    string cur;
    for (int pos = 0; pos < str.size();) {
      int len = 1;
      while (pos + len < str.size() && str[pos + len] == str[pos]) {
        ++len;
      }
      cur += to_string(len) + str[pos];
      pos += len;
    }
    return CountAndSay(cur, --n);
  }
};

class Solution 
{
public:
  string countAndSay(int n) 
  {
    string num("1"), next_num;
    
    for (int i = 1; i < n; ++ i)
    {
      int cnt = '0', last = num[0];
      next_num.clear();
      for (size_t j = 0; j < num.size(); ++ j)
      {
        if (num[j] == last)
        {
          ++ cnt;
        } else
        {
          next_num += cnt;
          next_num += last;
          cnt = '1';
          last = num[j];
        }
      }
      next_num += cnt;
      next_num += last;
      num = next_num;
    }

    return num;
  }
};
