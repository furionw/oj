class Solution 
{
public:
    int rob(vector<int> &num) 
    {
    	if (num.size() == 0)
    	{
    		return 0;
    	} else if (num.size() == 1)
    	{
    		return num[0];
    	}

    	// dp[i][1] stands for num[i] is added
        int dp[num.size()][2];
        dp[0][0] = 0;
        dp[0][1] = num[0];
        dp[1][0] = num[0];
        dp[1][1] = num[1];

        for (int i = 2; i < num.size(); ++ i)
        {
        	dp[i][0] = max(dp[i-1][0], dp[i-1][1]);
        	dp[i][1] = dp[i-1][0] + num[i];
        }

        return max(dp[num.size()-1][0], dp[num.size()-1][1]);
    }
};