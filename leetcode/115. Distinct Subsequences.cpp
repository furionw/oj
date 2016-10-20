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