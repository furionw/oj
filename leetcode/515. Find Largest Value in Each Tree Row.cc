// Copyright 2017 Qi Wang
// Date: 2017-03-17
class Solution {
 public:
  vector<int> largestValues(TreeNode* root) {
    vector<int> result;
    if (root != nullptr) f(root, 0, result);
    return result;
  }

 private:
  void f(TreeNode* root, int depth, vector<int>& result) const {
    if (depth + 1 > result.size()) {
      result.push_back(root->val);
    } else {
      result[depth] = max(result[depth], root->val);
    }
    if (root->left != nullptr) f(root->left, depth + 1, result);
    if (root->right != nullptr) f(root->right, depth + 1, result);
  }
};
