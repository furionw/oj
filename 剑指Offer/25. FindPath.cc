// Copyright 2017 Qi Wang
// Date: 2017-04-04
class Solution {
 public:
  vector<vector<int> > FindPath(TreeNode* root, int expectNumber) {
    vector<vector<int>> result;
    FindPath(root, expectNumber, vector<int>(), 0, result);
    return result;
  }

 private:
  void FindPath(TreeNode* root, int expect, vector<int> path,
      int sum, vector<vector<int>>& result) const {
    if (root == nullptr) return;
    sum += root->val;
    path.push_back(root->val);
    if (sum == expect && root->left == nullptr
        && root->right == nullptr)
      result.push_back(path);
    FindPath(root->left, expect, path, sum, result);
    FindPath(root->right, expect, path, sum, result);
  }
};
