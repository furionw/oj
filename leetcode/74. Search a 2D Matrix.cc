// Copyright 2017 Qi Wang
// Date: 2017-08-10
class Solution {
 public:
  bool searchMatrix(vector<vector<int>>& matrix, int target) {
    if (matrix.empty() || matrix[0].empty()) return false;
    int l = 0, r = matrix.size() - 1, row = INT_MIN;
    while (l <= r) {
      int mid = l + r >> 1;
      if (matrix[mid][0] == target) {
        return true;
      } else if (matrix[mid][0] < target) {
        if (mid + 1 == matrix.size() || matrix[mid + 1][0] > target) {
          row = mid;
          break;
        } else {
          l = mid + 1;
        }
      } else {
        r = mid - 1;
      }
    }
    if (row == INT_MIN) return false;
    return binary_search(matrix[row].begin(), matrix[row].end(), target);
  }
};

// Date: 2017-04-18
// Modified on: 2017-08-10
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
    // Use std::binary_search, rather than code manually here.
    return binary_search(matrix[bot].begin(), matrix[bot].end(), target);
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