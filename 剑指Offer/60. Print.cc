// Copyright 2017 Qi Wang
// Date: 2017-04-03
class Solution {
 public:
  vector<vector<int>> Print(TreeNode* pRoot) {
    vector<vector<int>> result;
    F(pRoot, 0, result);
    return result;
  }

 private:
  void F(TreeNode* root, int depth, vector<vector<int>>& result) const {
    if (root == nullptr) return;
    if (depth == result.size()) {
      result.push_back({root->val});
    } else {
      result[depth].push_back(root->val);
    }
    F(root->left, depth + 1, result);
    F(root->right, depth + 1, result);
  }
};
