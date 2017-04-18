// Copyright 2017 Qi Wang
// Date: 2017-04-18
class Solution {
 public:
  bool searchMatrix(vector<vector<int>>& matrix, int target) {
    if (matrix.empty() || matrix[0].empty()
        || matrix[0][0] > target || matrix.back().back() < target)
      return false;
    int up = 0, bot = matrix.size() - 1;
    while (up <= bot) {
      int mid = up + bot >> 1;
      if (matrix[mid][0] == target) {
        return true;
      } else if (matrix[mid][0] < target) {
        up = mid + 1;
      } else {
        bot = mid - 1;
      }
    }
    int left = 0, right = matrix[0].size() - 1;
    while (left <= right) {
      int mid = left + right >> 1;
      if (matrix[bot][mid] == target) {
        return true;
      } else if (matrix[bot][mid] < target) {
        left = mid + 1;
      } else {
        right = mid - 1;
      }
    }
    return false;
  }
};

// Date: 2014-08
class Solution {
 public:
  bool searchMatrix(vector<vector<int> > &matrix, int target) 
  {
    if (matrix.empty()==true || matrix[0][0]>target)
    {
      return false;
    }

    int l=0, r=matrix.size()-1, mid;
    while (l <= r)
    {
      mid = (l+r) >> 1;
      if (matrix[mid][0] < target)
      {
        l = mid + 1;
      } else if (matrix[mid][0] > target)
      {
        r = mid - 1;
      } else
      {
        return true; // ==
      }
    }
    int row = (l==matrix.size() || matrix[l][0]>target)? l-1: l;
    l=0, r=matrix[row].size()-1;
    while (l <= r)
    {
      mid = (l+r) >> 1;
      if (matrix[row][mid] < target)
      {
        l = mid + 1;
      } else if (matrix[row][mid] > target)
      {
        r = mid - 1;
      } else
      {
        return true;
      }
    }

    return false;
  }
};