class Solution 
{
public:
    int maxProduct(int A[], int n) 
    {
    	vector<vector<int>> dp = vector<vector<int>>(n, vector<int>(2));
    	int ret = A[0];
    	dp[0][0] = A[0];
    	dp[0][1] = A[0];

    	for (int i = 1; i < n; ++ i)
    	{
    		dp[i][0] = max(dp[i-1][0]*A[i], dp[i-1][1]*A[i]);
    		dp[i][0] = max(dp[i][0], A[i]);
    		dp[i][1] = min(dp[i-1][0]*A[i], dp[i-1][1]*A[i]);
    		dp[i][1] = min(dp[i][1], A[i]);
    		ret = max(ret, dp[i][0]);
    	}

    	return ret;
    }
};