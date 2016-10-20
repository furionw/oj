class Solution 
{
public:
    int minCut(string s) 
    {
    	vector<vector<bool>> palindrome(s.size(), vector<bool>(s.size(), false));
    	int dp[s.size()+1];
    	for (int i = 0; i < s.size()+1; ++ i)
    	{
    		dp[i] = static_cast<int>(s.size()) - i - 1;
    	}

    	for (int i = s.size()-1; i >= 0; -- i)
    	{
    		for (int j = i; j < s.size(); ++ j)
    		{
    			if (s[i]==s[j] && (j-i<=2 || palindrome[i+1][j-1]))
    			{
    				palindrome[i][j] = true;
    				dp[i] = min(dp[i], dp[j+1] + 1);
    			}
    		}
    	}

    	return dp[0];
    }
};