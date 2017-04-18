// Copyright 2017 Qi Wang
// Date: 2017-04-18
// Refer to: https://discuss.leetcode.com/topic/5056/any-shorter-o-1-space-solution
class Solution {
 public:
  void setZeroes(vector<vector<int>>& matrix) {
    if (matrix.empty()) return;
    int rows = matrix.size(), cols = matrix[0].size();
    bool col0 = false;
    for (int i = 0; i < rows; ++i) {
      if (0 == matrix[i][0]) col0 = true;
      for (int j = 1; j < cols; ++j)
        if (0 == matrix[i][j])
          matrix[i][0] = matrix[0][j] = 0;
    }
    // bottom-up order is necessary here
    for (int i = rows - 1; i >= 0; --i) {
      for (int j = 1; j < cols; ++j)
        if (0 == matrix[0][j] || 0 == matrix[i][0])
          matrix[i][j] = 0;
      if (col0) matrix[i][0] = 0;
    }
  }
};

// Date: 2017-04-18
class Solution {
 public:
  void setZeroes(vector<vector<int>>& matrix) {
    if (matrix.empty()) return;
    bool first_row = false, first_column = false;
    size_t n = matrix.size(), m = matrix[0].size();
    for (size_t i = 0; i < n; ++i)
      first_column = first_column || 0 == matrix[i][0];
    for (size_t j = 0; j < m; ++j)
      first_row = first_row || 0 == matrix[0][j];
    for (size_t i = 1; i < n; ++i)
      for (size_t j = 1; j < m; ++j)
        if (0 == matrix[i][j])
          matrix[i][0] = matrix[0][j] = 0;
    for (size_t i = 1; i < n; ++i)
      if (0 == matrix[i][0])
        fill(matrix[i].begin() + 1, matrix[i].end(), 0);
    for (size_t j = 1; j < m; ++j)
      if (0 == matrix[0][j])
        for (size_t i = 1; i < n; ++i)
          matrix[i][j] = 0;
    if (first_row)
      fill(matrix[0].begin(), matrix[0].end(), 0);
    if (first_column)
      for (size_t i = 0; i < n; ++i)
        matrix[i][0] = 0;
  }
};

// Date: 2014-08
class Solution 
{
public:
    void setZeroes(vector<vector<int> > &matrix) 
    {
        bool first_row=false, first_column=false;
        size_t n=matrix.size(), m=matrix[0].size();

        for (size_t j = 0; j < m; ++ j)
        {
            if (matrix[0][j] == 0)
            {
                first_row = true;
            }
        }    
        for (size_t i = 0; i < n; ++ i)
        {
            if (matrix[i][0] == 0)
            {
                first_column = true;
            }
        }
        for (size_t i = 1; i < n; ++ i)
        {
            for (size_t j = 1; j < m; ++ j)
            {
                if (matrix[i][j] == 0)
                {
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }
        for (size_t j = 1; j < m; ++ j)
        {
            if (matrix[0][j] == 0)
            {
                for (size_t i = 1; i < n; ++ i)
                {
                    matrix[i][j] = 0;
                }
            }
        }
        for (size_t i = 1; i < n; ++ i)
        {
            if (matrix[i][0] == 0)
            {
                for (size_t j = 1; j < m; ++ j)
                {
                    matrix[i][j] = 0;
                }
            }
        }
        if (first_row == true)
        {
            for (size_t j = 0; j < m; ++ j)
            {
                matrix[0][j] = 0;
            }
        }
        if (first_column == true)
        {
            for (size_t i = 0; i < n; ++ i)
            {
                matrix[i][0] = 0;
            }
        }
    }
};
