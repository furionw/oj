// Copyright 2017 Qi Wang
// Date: 2017-07-13
class Solution {
 public:
  vector<int> spiralOrder(vector<vector<int>>& matrix) {
    if (matrix.empty() || matrix[0].empty()) return {};
    vector<int> result;
    // l: left, r: right, u: up, d: down
    for (int u = 0, d = matrix.size() - 1,
        l = 0, r = matrix[0].size() - 1; l <= r && u <= d;
        ++l, --r, ++u, --d) {
      for (int j = l; j <= r; ++j)
        result.push_back(matrix[u][j]);
      for (int i = u + 1; i <= d; ++i)
        result.push_back(matrix[i][r]);
      if (u != d)
        for (int j = r - 1; j >= l; --j)
          result.push_back(matrix[d][j]);
      if (l != r)
        for (int i = d - 1; i > u; --i)
          result.push_back(matrix[i][l]);
    }
    return result;
  }
};

// Date: 2016-12-26
// Method 2: refer to the solution in 2014-07
class Solution {
 public:
  vector<int> spiralOrder(vector<vector<int>>& matrix) {
    if (matrix.empty() || matrix[0].empty()) return vector<int>();
    vector<int> res;
    for (int x1 = 0, y1 = 0, x2 = static_cast<int>(matrix.size()) - 1,
        y2 = static_cast<int>(matrix[0].size()) - 1;
        x1 <= x2 && y1 <= y2; ++x1, ++y1, --x2, --y2) {
      for (int j = y1; j <= y2; ++j) res.push_back(matrix[x1][j]);
      for (int i = x1 + 1; i <= x2; ++i) res.push_back(matrix[i][y2]);
      if (x1 != x2)
        for (int j = y2 - 1; j >= y1; --j) res.push_back(matrix[x2][j]);
      if (y1 != y2)
        for (int i = x2 - 1; i > x1; --i) res.push_back(matrix[i][y1]);
    }
    return res;
  }
};

// Date: 2016-12-26
// Method 1
class Solution {
 public:
  vector<int> spiralOrder(vector<vector<int>>& matrix) {
    if (matrix.empty() || matrix[0].empty()) return vector<int>();
    int m = static_cast<int>(matrix.size()),
        n = static_cast<int>(matrix[0].size());
    vector<int> res;
    res.reserve(m * n);
    for (int i = 0, j = 0; i < (m >> 1) + (m & 1) && j < (n >> 1) + (n & 1);
        ++i, ++j) {
      const int x1 = i, y1 = j, x2 = m - 1 - i, y2 = n - 1 - j;
      if (x1 == x2) {
        horizontalLine(matrix, x1, y1, y2, res);
      } else if (y1 == y2) {
        verticalLine(matrix, x1, x2, y1, res);
      } else {
        rectangle(matrix, x1, y1, x2, y2, res);
      }
    }
    return res;
  }

 private:
  // [y1, …, y2] inclusive
  void horizontalLine(const vector<vector<int>>& matrix,
      int i, int y1, int y2, vector<int>& res) const {
    for (int j = y1; j <= y2; ++j)
      res.push_back(matrix[i][j]);
  }

  // [x1, …, x2] inclusive
  void verticalLine(const vector<vector<int>>& matrix,
      int x1, int x2, int j, vector<int>& res) const {
    for (int i = x1; i <= x2; ++i)
      res.push_back(matrix[i][j]);
  }

  void rectangle(const vector<vector<int>>& matrix,
      int x1, int y1, int x2, int y2, vector<int>& res) const {
    for (int j = y1; j < y2; ++j)
      res.push_back(matrix[x1][j]);
    for (int i = x1; i < x2; ++i)
      res.push_back(matrix[i][y2]);
    for (int j = y2; j > y1; --j)
      res.push_back(matrix[x2][j]);
    for (int i = x2; i > x1; --i)
      res.push_back(matrix[i][y1]);
  }
};

// Date: 2014-07
class Solution 
{
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) 
    {
        if (matrix.empty() == true)
        {
            return vector<int>();
        }
        int x1 = 0, y1 = 0;
        int x2 = matrix.size()-1, y2 = matrix[0].size()-1;
        vector<int> ret;

        for ( ; x1<=x2 && y1<=y2; ++x1, ++y1, --x2, --y2)
        {
            for (int j = y1;   j <= y2; ret.push_back(matrix[x1][j++])) {} 
            for (int i = x1+1; i <= x2; ret.push_back(matrix[i++][y2])) {}
            for (int j = y2-1; x1!=x2 && j>=y1;   ret.push_back(matrix[x2][j--])) {} // x1!=x2
            for (int i = x2-1; y1!=y2 && i>=x1+1; ret.push_back(matrix[i--][y1])) {} // y1!=y2
        }

        return ret;
    }
};

// Date: 2014-07
class Solution 
{
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) 
    {
      if (matrix.empty() == true)
      {
        return vector<int>();
      }

      vector<int> ret;
      int row = 0, column = 0;
      int m = matrix.size(), n = matrix[0].size();
      for ( ; row<m/2 && column<n/2; ++ row, ++ column)
      {
        for (int j = column; j < n-column; ++ j)
        {
          ret.push_back( matrix[row][j] );
        }
        for (int i = row+1; i < m-row; ++ i)
        {
          ret.push_back( matrix[i][n-column-1] );
        }
        for (int j = n-column-2; j >= column; -- j)
        {
          ret.push_back( matrix[m-row-1][j] );
        }
        for (int i = m-row-2; i >= row+1; -- i)
        {
          ret.push_back( matrix[i][column] );
        }
      }
      if (m==n && m%2==1)
        {
            ret.push_back( matrix[row][column] );
    } else if (n%2==1 && row<m/2 && column>=n/2)
      {
        for (int bound=m-row; row < bound; ++ row)
        {
          ret.push_back( matrix[row][column] );
        }
      } else if (m%2==1 && row>=m/2 && column<n/2)
      {
        for (int bound=n-column; column < bound; ++ column)
        {
          ret.push_back( matrix[row][column] );
        }
      }

      return ret;
    }
};
