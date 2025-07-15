// 2025-07-14
class Solution {
 public:
  int maxProfit(vector<int>& prices) {
    int n = prices.size();
    int k = 2;
    vector<vector<vector<int>>> dp(
      n + 1,
      vector<vector<int>>(k + 1, vector<int>(2, 0))
    );
    for (int i = 0; i <= n; ++i) {
      for (int j = 0; j <= k; ++j) {
        dp[i][j][0] = -1e6;
      }
    }
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= k; ++j) {
        dp[i][j][0] = max(dp[i - 1][j][0], dp[i - 1][j - 1][1] - prices[i - 1]);
        dp[i][j][1] = max(dp[i - 1][j][1], dp[i - 1][j][0] + prices[i - 1]);
      }
    }
    return dp[n][k][1];
  }
};

// Date: 2016-10-06
class Solution {
 public:
  int maxProfit(vector<int>& prices) {
    if (prices.size() <= 1) return 0;
    // first time
    vector<int> firstTime(prices.size(), 0);
    int lowestBuyPrice = prices[0];
    for (size_t i = 1; i < prices.size(); ++i) {
    	lowestBuyPrice = min(lowestBuyPrice, prices[i]);    	
    	firstTime[i] = max(firstTime[i - 1], prices[i] - lowestBuyPrice);
    }
    // second time
    int res = 0;
    int highestSellPrice = prices.back();
    for (int i = prices.size() - 2; i >= 0; --i) {
    	highestSellPrice = max(highestSellPrice, prices[i]);
    	// Remember add parenthesis for ?
    	// References: http://en.cppreference.com/w/cpp/language/operator_precedence
      res = max(res, highestSellPrice - prices[i]
      	  + (i >= 2 ? firstTime[i - 1] : 0));
    }
    return res;
  }
};

// Date: 2014-08
class Solution
{
public:
	int maxProfit(vector<int>& prices)
	{
		if (prices.size() <= 1)
		{
			return 0;
		}

		vector<int> first_time(prices.size(), 0);
		int min_price = prices.front();
		for (size_t i = 1; i < prices.size(); ++ i)
		{
			min_price = min(min_price, prices[i]);
			first_time[i] = max(first_time[i-1], prices[i]-min_price);
		}
		int max_price = prices.back();
		int max_profit = *max_element(first_time.begin(), first_time.end());
		for (int i = prices.size()-2; i >= 1; -- i)
		{
			max_price = max(max_price, prices[i]);
			max_profit = max(max_profit, first_time[i-1] + max_price - prices[i]);
		}

		return max_profit;
	}
};