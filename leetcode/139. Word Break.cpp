// Copyright 2016 Qi Wang
// Date: 2016-10-10
class Solution {
 public:
  bool wordBreak(string s, unordered_set<string> &dict) {
    vector<int> dp(s.size(), false);
    for (size_t i = 0; i < s.size(); ++i) {
      dp[i] = dict.find(s.substr(0, i + 1)) != dict.end();
      for (size_t j = 0; j < i && !dp[i]; ++j)
        dp[i] = dp[j] && dict.find(s.substr(j + 1, i - j)) != dict.end();
    }
    return dp.back();
  }
};

// Date: 2015-03
class Solution {
 public:
  bool wordBreak(string s, unordered_set<string> &dict) {
    vector<bool> dp(s.size() + 1, false);
    dp[0] = true;
    for (size_t i = 0; i < s.size(); ++ i) {
  	  if (dp[i] == true) {
		for (size_t length = 1; i + length <= s.size(); ++ length) {
		  dp[i + length] = dp[i + length]? true: 
	  	 	  dict.find(s.substr(i, length))!=dict.end();
		}
	  }
    }
    return dp[s.size()];
  }
};
