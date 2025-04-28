// Date: 2022-12-14
class Solution {
 public:
  int climbStairs(int n) {
    vector<int> dp(n + 1, 0);
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i <= n; ++i) {
      dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp.back();
  }
};

class Solution 
{
public:
    int climbStairs(int n) 
    {
    	int prev=1, prevv=1, ret=1;
    	for (int i = 2; i <= n; ++ i)
    	{
    		ret = prev + prevv;
    		prevv = prev;
    		prev = ret;
    	}
    	return ret;
    }
};
