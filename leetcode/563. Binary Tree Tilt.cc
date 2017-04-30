// Copyright 2017 Qi Wang
// Date: 2017-04-23
class Solution {
 public:
  int findTilt(TreeNode* root) {
    return TiltAndSum(root).first;
  }
 
 private:
  pair<int, int> TiltAndSum(TreeNode* root) const {
    if (root == nullptr) return {0, 0};
    auto left = TiltAndSum(root->left), right = TiltAndSum(root->right);
    return {left.first + abs(left.second - right.second) + right.first,
        left.second + root->val + right.second};
  }
};
