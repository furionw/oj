#include <algorithm>
#include <string>
#include <vector>
#include <iostream>

using namespace  std;

class Solution 
{
public:
    int minDistance(string word1, string word2) 
    {
    	if (word1.size()==0 || word2.size()==0)
    	{
    		return word1.size()+word2.size();
    	}

    	size_t n=word1.size(), m=word2.size();
    	vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

    	for (int j = 1; j <= m; ++ j)
    	{
    		dp[0][j] = j;
    	}
		for (int i = 1; i <= n; ++ i)
		{
			dp[i][0] = i;
		}
    	for (size_t i = 1; i <= n; ++ i)
    	{
    		for (size_t j = 1; j <= m; ++ j)
    		{
//				cout << "dp[i-1][j]+1: " << dp[i-1][j]+1 << endl;
//				cout << "dp[i][j-1]+1: " << dp[i][j-1]+1 << endl;
    			dp[i][j] = min(dp[i-1][j]+1, dp[i][j-1]+1);
//				cout << i << " " << j << ": " << dp[i][j] << endl;
//				cout << "dp[i-1][j-1]: " << dp[i-1][j-1] << endl;
				dp[i][j] = min(dp[i][j], dp[i-1][j-1]+(word1[i-1]==word2[j-1]?0: 1));
//				cout << i << " " << j << ": " << dp[i][j] << endl;
			}
    	}

    	return dp[n][m];
    }
};

int main()
{
	Solution a;
	a.minDistance("a", "ab");

	return 0;
}