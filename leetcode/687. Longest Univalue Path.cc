// Copyright 2017 Qi Wang
// Date: 2017-10-15
class Solution {
 public:
  int longestUnivaluePath(TreeNode* root) {
    int result = 0;
    F(root, &result);
    return result;
  }
 
 private:
  int F(TreeNode* node, int* result) const {
    if (node == nullptr) return 0;
    int single_side_len = 0;
    int left = F(node->left, result);
    if (node->left != nullptr && node->val == node->left->val) {
      single_side_len = left + 1;
    }
    int right = F(node->right, result);
    if (node->right != nullptr && node->val == node->right->val) {
      single_side_len = max(single_side_len, right + 1);
    }
    if ((node->left != nullptr && node->val == node->left->val) &&
        (node->right != nullptr && node->val == node->right->val)) {
      *result = max(*result, left + right + 2);
    }
    *result = max(*result, single_side_len);
    return single_side_len;
  }
};
