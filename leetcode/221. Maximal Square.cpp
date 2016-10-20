#include <vector>
#include <algorithm>

using namespace std;

class Solution 
{
public:
    int maximalSquare(vector<vector<char>>& matrix) 
    {
    	if (matrix.size() == 0)
    	{
    		return 0;
    	}

    	int max_length = 0;
        vector<vector<int>> dp(matrix.size(), vector<int>(matrix[0].size(), 0));
        for (size_t i  = 0; i < matrix.size(); ++ i)
        {
        	dp[i][0] = matrix[i][0] - '0';
        	max_length = max(max_length, dp[i][0]);
        }
        for (size_t j = 0; j < matrix[0].size(); ++ j)
        {
        	dp[0][j] = matrix[0][j] - '0';
        	max_length = max(max_length, dp[0][j]);
        }
        for (size_t i = 1; i < matrix.size(); ++ i)
        {
        	for (size_t j = 1; j < matrix.size(); ++ j)
        	{
        		int pre_length = dp[i-1][j-1];
        		bool new_square = true;
        		for (size_t k = 0; k <= pre_length && new_square; ++ k)
        		{
        			new_square = new_square && (matrix[i-k][j] == '1');
        			new_square = new_square && (matrix[i][j-k] == '1');
        		} 
        		max_length = max(max_length, new_square? (pre_length+1)	: 0);
        	}
        }
        return max_length * max_length;
    }
};

