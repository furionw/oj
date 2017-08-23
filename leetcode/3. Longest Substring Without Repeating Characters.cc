// Copyright 2017 Qi Wang
// Date: 2017-08-22
class Solution {
 public:
  int lengthOfLongestSubstring(string s) {
    unordered_map<char, int> char_to_idx_map;
    int begin = 0, cnt = 0;
    for (int i = 0; i < s.size(); ++i) {
      if (char_to_idx_map.count(s[i])) {
        for (; begin <= char_to_idx_map[s[i]]; ++begin) {
          char_to_idx_map.erase(s[begin]);
        }
      }
      char_to_idx_map[s[i]] = i;
      cnt = max(cnt, i - begin + 1);
    }
    return cnt;
  }
};

// Date: 2016-12-18
class Solution {
 public:
  int lengthOfLongestSubstring(string s) {
    int begin = 0, res = 0;
    unordered_set<char> cs;
    for (int i = 0; i < static_cast<int>(s.size()); ++i) {
      while (cs.count(s[i]) > 0)
        cs.erase(s[begin++]);
      cs.insert(s[i]);
      res = max(res, i + 1 - begin);
    }
    return res;
  }
};

// Date: 2016-03
// Revisited on 2016-12-18
class Solution {
 public:
  int lengthOfLongestSubstring(string s) {
    int length = 0;
    string substr;
    for (char c: s) {
      if (substr.find(c) == string::npos) {
        substr += c;
        length = max(length, static_cast<int>(substr.size()));
      } else {
        substr = substr.substr(substr.find(c) + 1) + c;
      }
    }
    return length;
  }
};

// Date: 2014-06
class Solution 
{
public:
  int lengthOfLongestSubstring(string s) 
  {
    if (s.size()==0)
    {
      return 0;
    }

    vector<int> dp(s.size(), 0);
    int max=1;

    dp[0] = 1;
    for (int i = 1; i < s.size(); ++ i)
    {
      for (int j = i-1; j>=i-dp[i-1]; -- j)
      {
        if (s[i] == s[j])
        {
          dp[i] = i-j;
          break;
        }
      }
      dp[i] = dp[i]==0? dp[i-1]+1: dp[i];
      max = dp[i]>max? dp[i]: max;
    }

    return max;
  }
};
