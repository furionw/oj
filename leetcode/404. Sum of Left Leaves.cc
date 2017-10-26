// Copyright 2017 Qi Wang
// Date: 2017-10-25
// Method 2
// Refer to the solution on 2017-07-20
class Solution {
 public:
  int sumOfLeftLeaves(TreeNode* root) {
    return Dfs(root, false);
  }

 private:
  int Dfs(TreeNode* root, bool is_left) const {
    if (root == nullptr) return 0;
    if (root->left == nullptr && root->right == nullptr) {
      return is_left ? root->val : 0;
    } else {
      return Dfs(root->left, true) + Dfs(root->right, false);
    }
  }
};

// Date: 2017-10-25
// Method 1
// Case 1: [0, 1, 2]
class Solution {
 public:
  int sumOfLeftLeaves(TreeNode* root) {
    if (root == nullptr) return 0;
    int result = 0;
    Right(root, &result);
    return result;
  }

 private:
  void Left(TreeNode* root, int* result) const {
    if (root == nullptr) return;
    if (root->left == nullptr && root->right == nullptr) {
      *result += root->val;
    } else {
      Left(root->left, result);
      Right(root->right, result);
    }
  }

  void Right(TreeNode* root, int* result) const {
    if (root == nullptr) return;
    Left(root->left, result);
    Right(root->right, result);
  }
};

// Date: 2017-07-20
class Solution {
 public:
  int sumOfLeftLeaves(TreeNode* root) {
    return Dfs(root, false);
  }

 private:
  int Dfs(TreeNode* root, bool is_left) const {
    if (nullptr == root) return 0;
    if (nullptr == root->left && nullptr == root->right) {
      return is_left ? root->val : 0;
    } else {
      return Dfs(root->left, true) + Dfs(root->right, false);
    }
  }
};
