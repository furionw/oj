// 2025-05-04
class NumMatrix {
 public:
    NumMatrix(vector<vector<int>>& matrix)
        : m(matrix.size()), n(matrix[0].size()),
          trees(m, vector<int>(n * 2, -1)) {
      for (int i = 0; i < m; ++i) {
        buildTree(matrix[i], trees[i]);
      }
    }
    
    void update(int row, int col, int val) {
      auto& tree = trees[row];
      int delta = val - tree[col + n];
      for (int i = col + n; i > 0; i /= 2) {
        tree[i] += delta;
      }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
      int result = 0;
      for (int i = row1; i <= row2; ++i) {
        result += sumRegion(trees[i], col1, col2);
      }
      return result;
    }

 private:
  void buildTree(const vector<int>& nums, vector<int>& tree) {
    for (int i = n; i < 2 * n; ++i) {
      tree[i] = nums[i - n];
    }
    for (int i = n - 1; i > 0; --i) {
      tree[i] = tree[2 * i] + tree[2 * i + 1];
    }
  }

  int sumRegion(const vector<int>& tree, int l, int r) {
    int result = 0;
    l += n;
    r += n;
  
    while (l <= r) {
      if (l % 2 == 1) {
        result += tree[l];
        l = l / 2 + 1;
      } else {
        l /= 2;
      }
      if (r % 2 == 0) {
        result += tree[r];
        r = r / 2 - 1;
      } else {
        r /= 2;
      }
    }

    return result;
  }

  int m;
  int n;
  vector<vector<int>> trees;
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * obj->update(row,col,val);
 * int param_2 = obj->sumRegion(row1,col1,row2,col2);
 */

// Date: 2017-09-10
// Refer to: https://www.topcoder.com/community/data-science/data-science-tutorials/binary-indexed-trees/
class BIT {
 public:
  BIT(const vector<int>& nums) {
    nums_.resize(nums.size() + 1);
    copy(nums.begin(), nums.end(), nums_.begin() + 1);
    tree_ = nums_;
    tree_[0] = 0;
    for (int i = 1; i < nums_.size(); ++i) {
      tree_[i] += tree_[i - 1];
    }
    for (int i = 1; i < tree_.size(); ++i) {
      for (int idx = i - (i & -i); idx != 0; idx -= (idx & -idx)) {
        tree_[i] -= tree_[idx];
      }
    }
  }
 
  int Sum(int l, int r) const {
    return Sum(r) - Sum(l - 1);
  }
 
  void Update(int idx, int val) {
    int delta = val - nums_[idx];
    nums_[idx] += delta;
    for (; idx < tree_.size(); idx += (idx & -idx)) {
      tree_[idx] += delta;
    }
  }
 
 private:
  int Sum(int idx) const {
    int sum = 0;
    while (idx > 0) {
      sum += tree_[idx];
      idx -= (idx & -idx);
    }
    return sum;
  }
 
  vector<int> tree_;
  vector<int> nums_;
};
 
class NumMatrix {
 public:
  NumMatrix(vector<vector<int>> matrix) {
    for (const auto& nums : matrix) {
      trees_.emplace_back(nums);
    }
  }
  
  void update(int row, int col, int val) {
    trees_[row].Update(col + 1, val);
  }
  
  int sumRegion(int row1, int col1, int row2, int col2) {
    int sum = 0;
    for (int i = row1; i <= row2; ++i) {
      sum += trees_[i].Sum(col1 + 1, col2 + 1);
    }
    return sum;
  }
 
 private:
  vector<BIT> trees_;
};
