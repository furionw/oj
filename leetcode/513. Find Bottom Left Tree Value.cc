// Copyright 2017 Qi Wang
// Date: 2017-02-25
class Solution {
 public:
  int findBottomLeftValue(TreeNode* root) {
    int max_depth = -1, result = INT_MAX;
    findBottomLeftValue(root, max_depth + 1, max_depth, result);
    return result;
  }
 
 private:
  void findBottomLeftValue(TreeNode* root, int cur_depth,
      int& max_depth, int& result) {
    if (cur_depth > max_depth) {
      result = root->val;
      max_depth = cur_depth;
    }
    if (root->left != nullptr)
      findBottomLeftValue(root->left, cur_depth + 1, max_depth, result);
    if (root->right != nullptr)
      findBottomLeftValue(root->right, cur_depth + 1, max_depth, result);
  }
};
