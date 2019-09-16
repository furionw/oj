// Copyright 2019 Qi Wang
// Date: 2019-09-14
class Solution {
 public:
  int maxAncestorDiff(TreeNode* root) {
    vector<int> ancestors;
    int result = INT_MIN;
    maxAncestorDiff(root, &ancestors, &result);
    return result;
  }

 private:
  void maxAncestorDiff(TreeNode* root, vector<int>* ancestors,
                       int* result) const {
    if (root == nullptr) {
      return;
    }
    for (int ancestor: *ancestors) {
    // for (const auto&& ancestor: *ancestors) {
      *result = max(*result, abs(root->val - ancestor));
    }
    ancestors->push_back(root->val);
    maxAncestorDiff(root->left, ancestors, result);
    maxAncestorDiff(root->right, ancestors, result);
    ancestors->pop_back();
  }
};
