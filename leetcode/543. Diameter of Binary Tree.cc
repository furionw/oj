// 2025-05-06
// Refer to past solution
class Solution {
 public:
  int diameterOfBinaryTree(TreeNode* root) {
    int result = 0;
    depth(root, result);
    return result;
  }
 
 private:
  int depth(TreeNode* root, int& result) {
    if (root == nullptr) {
      return 0;
    }
    int l = depth(root->left, result);
    int r = depth(root->right, result);
    result = max(result, l + r);
    return max(l, r) + 1;
  }
};

// 2025-05-06
class Solution {
 public:
  int diameterOfBinaryTree(TreeNode* root) {
    auto result = impl(root);
    return max(result.first, result.second);
  }
 
 private:
  pair<int, int> impl(TreeNode* root) {
    if (root->left == nullptr && root->right == nullptr) {
      return {0, 0};
    } else if (root->left != nullptr && root->right != nullptr) {
      auto l = impl(root->left);
      auto r = impl(root->right);
      return {
        max(l.first, r.first) + 1,
        max(
            max(l.second, r.second),
            l.first + r.first + 2
        ),
      };
    } else if (root->left != nullptr) {
      auto l = impl(root->left);
      return {l.first + 1, l.second};
    } else {
      auto r = impl(root->right);
      return {r.first + 1, r.second};
    }
  }
};

// 2017-10-26
class Solution {
 public:
  int diameterOfBinaryTree(TreeNode* root) {
    int result = 0;
    Dfs(root, &result);
    return result;
  }
 
 private:
  int Dfs(TreeNode* root, int* result) const {
    if (root == nullptr) return -1;
    int left = Dfs(root->left, result);
    int right = Dfs(root->right, result);
    *result = max(*result, left + right + 2);
    return max(left, right) + 1;
  }
};

// Date: 2017-08-04
class Solution {
 public:
  int diameterOfBinaryTree(TreeNode* root) {
    int result = 0;
    F(root, &result);
    return result;
  }
 
 private:
  int F(TreeNode* root, int* result) const {
    if (root == nullptr) return 0;
    int left = F(root->left, result);
    int right = F(root->right, result);
    *result = max(*result, left + right);
    return 1 + max(left, right);
  }
};

// Date: 2017-04-02
class Solution {
 public:
  int diameterOfBinaryTree(TreeNode* root) {
    if (root == nullptr) return 0;
    auto result = F(root);
    return max(result.first, result.second) - 1;
  }

 private:
  // first: longest path to its leaf, second: diameter of subroot
  pair<int, int> F(TreeNode* root) const {
    if (root == nullptr) return {0, 0};
    auto left = F(root->left);
    auto right = F(root->right);
    return {max(left.first, right.first) + 1,
        max(max(left.second, right.second), left.first + right.first + 1)};
  }
};
