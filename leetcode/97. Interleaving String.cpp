class Solution 
{
public:
    bool isInterleave(string s1, string s2, string s3) 
    {
        vector<vector<bool>> dp(s1.size()+1, vector<bool>(s2.size()+1, true));

        for (size_t i = 1; i <= s1.size(); ++ i)
        {
	        dp[i][0] = s1.substr(0, i)==s3.substr(0, i);
        }
        for (size_t j = 1; j <= s2.size(); ++ j)
        {
        	dp[0][j] = s2.substr(0, j)==s3.substr(0, j);
        }
        for (size_t i = 1; i <= s1.size(); ++ i)
        {
        	for (size_t j = 1; j <= s2.size(); ++ j)
        	{
        		dp[i][j] = (dp[i-1][j]==true && s1[i-1]==s3[i+j-1])
        				|| (dp[i][j-1]==true && s2[j-1]==s3[i+j-1]);
        	}
        }

        return s1.size()+s2.size()!=s3.size()? false: dp[s1.size()][s2.size()];
    }
};