// Copyright 2017 Qi Wang
// Date: 2017-07-19
class Solution {
 public:
  void rotate(vector<vector<int>>& matrix) {
    int n = matrix.size();
    for (int pos1 = 0; pos1 < n / 2; ++pos1) {
      int pos2 = n - pos1 - 1;
      for (int k = pos1; k < pos2; ++k) {
        swap(matrix[pos1][k], matrix[k][pos2]);
        swap(matrix[pos1][k], matrix[pos2][pos2 - (k - pos1)]);
        swap(matrix[pos1][k], matrix[pos2 - (k - pos1)][pos1]);
      }
    }
  }
};

class Solution 
{
public:
    void rotate(vector<vector<int> > &matrix) 
    {
      // 要用int, 否则matrix.size()==2时，-- bottom_right溢出
        for (int top_left=0, bottom_right=matrix.size()-1; top_left < bottom_right; 
          ++ top_left, -- bottom_right)
        {
          for (size_t i = 0; i < bottom_right - top_left; ++ i)
          {
            swap(matrix[top_left][top_left+i], matrix[top_left+i][bottom_right]);
            swap(matrix[top_left][top_left+i], matrix[bottom_right-i][top_left]);
            swap(matrix[bottom_right-i][top_left], matrix[bottom_right][bottom_right-i]);
          }
        }
    }
};