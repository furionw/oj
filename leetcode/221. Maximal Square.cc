// Copyright 2017 Qi Wang
// Date: 2017-11-10
// Refer to: https://discuss.leetcode.com/topic/15328/easy-dp-solution-in-c-with-detailed-explanations-8ms-o-n-2-time-and-o-n-space
class Solution {
 public:
  int maximalSquare(vector<vector<char>>& matrix) {
    if (matrix.empty() || matrix[0].empty()) return 0;
    int m = matrix.size(), n = matrix[0].size();
    vector<int> dp(n + 1, 0);
    int max_sz = 0;
    for (int i = 0; i < m; ++i) {
      for (int j = 1; j <= n; ++j) {
        if (matrix[i][j - 1] == '1') {
          int k = min(dp[j - 1], dp[j]);
          dp[j] = matrix[i - k][j - k - 1] == '1' ? k + 1 : k;
          max_sz = max(max_sz, dp[j]);
        } else {
          dp[j] = 0;
        }
      }
    }
    return max_sz * max_sz;
  }
};

// Date: 2017-08-15
// Please refer to other's solutions for more concise and efficient impl
class Solution {
 public:
  int maximalSquare(vector<vector<char>>& matrix) {
    if (matrix.empty() || matrix[0].empty()) return 0;
    int m = matrix.size(), n = matrix[0].size();
    vector<vector<int>> dp(m, vector<int>(n, 0));
    auto hor = dp, ver = dp;
    int result = 0;
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        hor[i][j] = matrix[i][j] == '0'
            ? 0 : 1 + (j > 0 ? hor[i][j - 1] : 0);
        dp[i][j] = matrix[i][j] != '0';
        result = max(result, dp[i][j]);
      }
    }
    for (int j = 0; j < n; ++j) {
      for (int i = 0; i < m; ++i) {
        ver[i][j] = matrix[i][j] == '0'
            ? 0 : 1 + (i > 0 ? ver[i - 1][j] : 0);
      }
    }
    for (int i = 1; i < m; ++i) {
      for (int j = 1; j < n; ++j) {
        dp[i][j] = min(ver[i][j], min(hor[i][j], dp[i - 1][j - 1] + 1));
        result = max(result, dp[i][j] * dp[i][j]);
      }
    }
    return result;
  }
};

// Date: 2017-08-02
class Solution {
 public:
  int maximalSquare(vector<vector<char>>& matrix) {
    if (matrix.empty() || matrix[0].empty()) return 0;
    int m = matrix.size(), n = matrix[0].size();

    vector<vector<int>> hor(m, vector<int>(n, 0));
    vector<vector<int>> ver(m, vector<int>(n, 0));
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        hor[i][j] = ver[i][j] = matrix[i][j] - '0';
        if (j > 0 && matrix[i][j] == '1') hor[i][j] += hor[i][j - 1];
        if (i > 0 && matrix[i][j] == '1') ver[i][j] += ver[i - 1][j];
      }
    }
    vector<vector<int>> dp(m, vector<int>(n, 0));
    int result = 0;
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        dp[i][j] = matrix[i][j] - '0';
        if (i > 0 && j > 0 && matrix[i][j] == '1')
          dp[i][j] = min(dp[i - 1][j - 1] + 1, min(hor[i][j], ver[i][j]));
        result = max(result, dp[i][j]);
      }
    }
    return result * result;
  }
};

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

