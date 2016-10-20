// Copyright 2016 Qi Wang
// Date: 2016-10-06
class Solution {
 public:
  int maxProfit(vector<int>& prices) {
    if (prices.size() <= 1) return 0;
    int res = 0, highestSellPrice = 0;
    for (int i = prices.size() - 1; i >= 0; --i) {
      highestSellPrice = max(prices[i], highestSellPrice);
      res = max(res, highestSellPrice - prices[i]);
    }
    return res;
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

        int max_price = prices.back();
        int max_profit = 0;
        for (int i = int(prices.size())-1; i >= 0; -- i)
        {
        	max_price = max(max_price, prices[i]);
        	max_profit = max(max_profit, max_price-prices[i]);
        }
        return max_profit;
    }
};