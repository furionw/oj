// Copyright 2016 Qi Wang
// Date: 2016-11-01
class Solution {
 public:
  inline int numDistinct(string s, string t) {
    int dp[s.size() + 1][t.size() + 1];
    for (size_t i = 0; i < s.size() + 1; ++i)
      dp[i][0] = 1;
    for (size_t j = 1; j < t.size() + 1; ++j)
      dp[0][j] = 0;
    for (size_t i = 1; i <= s.size(); ++i)
      for (size_t j = 1; j <= t.size(); ++j)
        dp[i][j] = dp[i - 1][j] + (s[i - 1] == t[j - 1] ? dp[i - 1][j - 1] : 0);
    return dp[s.size()][t.size()];
  }
};

// Date: 2014-08
class Solution 
{
public:
    int numDistinct(string S, string T) 
    {
        vector<vector<int>> dp(S.size()+1, vector<int>(T.size()+1, 0));

        for (size_t i = 0; i <= S.size(); ++ i)
        {
        	dp[i][0] = 1;
        }
        for (size_t i = 1; i <= S.size(); ++ i)        
        {
            for (size_t j = 1; j <= T.size(); ++ j)        
        	{
        		dp[i][j] = dp[i-1][j] + (S[i-1]==T[j-1]? dp[i-1][j-1]: 0); // do use bracket here
        	}
        }

        return dp[S.size()][T.size()];
    }
};