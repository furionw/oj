// Copyright 2016 Qi Wang
// Reference: https://discuss.leetcode.com/topic/57705/share-slightly-different-concise-dp-approach-o-n-k-o-k-memory-beats-99
// Date: 2016-10-06
class Solution {
 public:
  int maxProfit(vector<int>& prices) {
    if (prices.size() < 2) return 0;
    int prof = 0;
    for (size_t i = 1; i < prices.size(); ++i)
      prof += prices[i] > prices[i - 1] ? prices[i] - prices[i - 1] : 0;
    return prof;
  }
};

// Date: 2016-10-06
class Solution {
 public:
  int maxProfit(vector<int>& prices) {
    if (prices.empty()) return 0;
    vector<vector<int>> dp(prices.size(), vector<int>(2, 0));
    // init
    dp[0][0] = 0;
    dp[0][1] = -prices[0];
    for (size_t i = 1; i < prices.size(); ++i) {
      dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
      dp[i][1] = max(dp[i - 1][1], dp[i][0] - prices[i]);
    }
    return dp[prices.size() - 1][0];
  }
};

// Date: 2014-08
class Solution 
{
public:
    int maxProfit(vector<int> &prices) 
    {
    	if(prices.empty())
    	{
    		return 0;
    	}

        vector<vector<int>> dp(prices.size(), vector<int>(2, 0));
        dp[0][0] = 0;
        dp[0][1] = -prices[0];
        for (size_t i = 1; i < prices.size(); ++ i)
        {
            dp[i][0] = max(dp[i-1][0], dp[i-1][1]+prices[i]);
            dp[i][1] = max(dp[i-1][1], dp[i-1][0]-prices[i]);
        }

        return dp[prices.size()-1][0];
    }
};
