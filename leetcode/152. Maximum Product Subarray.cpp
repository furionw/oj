// supported by GCC compilor
class Solution 
{
public:
    int maxProduct(int A[], int n) 
    {
		int dp[2][n];
		dp[0][0] = A[0];
		dp[1][0] = A[0];

		for (int i = 1; i < n; ++ i)
		{
			dp[0][i] = max(dp[0][i-1]*A[i], dp[1][i-1]*A[i]);
			dp[0][i] = max(dp[0][i], A[i]);
			dp[1][i] = min(dp[0][i-1]*A[i], dp[1][i-1]*A[i]);
			dp[1][i] = min(dp[1][i], A[i]);
		}

		return *max_element(dp[0], dp[0]+n);
    }
};