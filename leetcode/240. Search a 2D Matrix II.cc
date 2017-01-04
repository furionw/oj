// Copyright 2017 Qi Wang
// Date: 2017-01-04
// Method 3: refer to https://discuss.leetcode.com/topic/19477/c-with-o-m-n-complexity
class Solution {
 public:
  bool searchMatrix(vector<vector<int>>& matrix, int target) {
    if (matrix.empty() || matrix[0].empty()) return false;
    int m = matrix.size(), n = matrix[0].size();
    int i = 0, j = n - 1;
    while (i < m && j >= 0) {
      if (matrix[i][j] == target) {
        return true;
      } else if (matrix[i][j] < target) {
        ++i;
      } else {
        --j;
      }
    }
    return false;
  }
};

// Date: 2017-01-04
// Method 2
// This method is not good. 'Cause we divive the matrix into 4 parts, and
// handle 3 out of 4 parts.
class Solution {
 public:
  bool searchMatrix(vector<vector<int>>& matrix, int target) {
    if (matrix.empty() || matrix[0].empty()) return false;
    return searchMatrix(matrix, 0, 0,
        matrix.size() - 1, matrix[0].size() - 1, target);
  }

 private:
  bool searchMatrix(const vector<vector<int>>& matrix, int x1, int y1,
      int x2, int y2, int target) const {
    if (x1 + 1 >= x2) {
      return hor(matrix, x1, y1, y2, target)
          || (x1 + 1 == x2 ? hor(matrix, x2, y1, y2, target) : false);
    } else if (y1 + 1 >= y2) {
      return ver(matrix, x1, x2, y1, target)
          || (y1 + 1 == y2 ? ver(matrix, x1, x2, y2, target) : false);
    // We're handling the matrix with size at least 3 * 3
    } else {
      int x_mid = (x1 + x2) >> 1, y_mid = (y1 + y2) >> 1;
      if (matrix[x_mid][y_mid] == target) {
        return true;
      } else if (target < matrix[x_mid][y_mid]) {
        return searchMatrix(matrix, x1, y1, x_mid - 1, y2, target)
            || searchMatrix(matrix, x_mid, y1, x2, y_mid - 1, target);
      } else {
        return searchMatrix(matrix, x1, y_mid + 1, x2, y2, target)
            || searchMatrix(matrix, x_mid + 1, y1, x2, y_mid, target);
      }
    }
  }

  // horizontal
  bool hor(const vector<vector<int>>& matrix, int i, int y1, int y2, int target)
      const {
      return binary_search((matrix.begin() + i)->begin() + y1,
          (matrix.begin() + i)->begin() + y2 + 1, target);
  }

  // vertical
  bool ver(const vector<vector<int>>& matrix, int x1, int x2, int j, int target)
      const {
    for (int up = x1, bot = x2; up <= bot;) {
      int mid = (up + bot) >> 1;
      if (matrix[mid][j] == target) {
        return true;
      } else if (matrix[mid][j] < target) {
        up = mid + 1;
      } else {
        bot = mid - 1;
      }
    }
    return false;    
  }
};

// Date: 2017-01-04
// Method 1
class Solution {
 public:
  bool searchMatrix(vector<vector<int>>& matrix, int target) {
    if (matrix.empty() || matrix[0].empty()) return false;
    int m = matrix.size(), n = matrix[0].size();

    // calculate i_end
    int i_begin = 0, i_end = m - 1;
    while (i_begin <= i_end) {
      int mid = (i_begin + i_end) >> 1;
      if (matrix[mid][0] == target) {
        return true;
      } else if (matrix[mid][0] < target) {
        i_begin = mid + 1;
      } else {
        i_end = mid - 1;
      }
    }
    i_end = max(0, i_end);
    for (; i_end < m && matrix[i_end][0] < target; ++i_end) {}

    // calculate i_begin
    i_begin = 0;
    for (int i_end_temp = i_end - 1; i_begin <= i_end_temp;) {
      int mid = (i_begin + i_end_temp) >> 1;
      if (matrix[mid][n - 1] == target) {
        return true;
      } else if (matrix[mid][n - 1] < target) {
        i_begin = mid + 1;
      } else {
        i_end_temp = mid - 1;
      }
    }
    i_begin = min(m - 1, i_begin);
    for (; i_begin >= 0 && matrix[i_begin][n - 1] > target; --i_begin) {}

    return any_of(matrix.begin() + i_begin + 1, matrix.begin() + i_end,
        [target](const vector<int>& vt) {
          return binary_search(vt.begin(), vt.end(), target);
        });
  }
};
