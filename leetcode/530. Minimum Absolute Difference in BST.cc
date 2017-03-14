// Copyright 2017 Qi Wang
// Date: 2017-03-14
// Refer to: https://discuss.leetcode.com/topic/80836/c-7-lines-o-n-run-time-o-h-memory
// O(h) space
class Solution {
 public:
  int getMinimumDifference(TreeNode* root) {
    int prev = -1, min_diff = INT_MAX;
    inorder(root, prev, min_diff);
    return min_diff;
  }

 private:
  void inorder(TreeNode* root, int& prev, int& min_diff) {
    if (root->left != nullptr) inorder(root->left, prev, min_diff);
    if (prev >= 0) min_diff = min(min_diff, root->val - prev);
    prev = root->val;
    if (root->right != nullptr) inorder(root->right, prev, min_diff);
  }
};

// Date: 2017-03-14
// O(n) space
class Solution {
 public:
  int getMinimumDifference(TreeNode* root) {
    vector<int> nums;
    inorder(root, nums);
    int min_diff = INT_MAX;
    for (size_t i = 1; i < nums.size(); ++i)
      min_diff = min(min_diff, nums[i] - nums[i - 1]);
    return min_diff;
  }

 private:
  void inorder(TreeNode* root, vector<int>& nums) {
    if (root->left != nullptr) inorder(root->left, nums);
    nums.push_back(root->val);
    if (root->right != nullptr) inorder(root->right, nums);
  }
};
