// Copyright 2017 Qi Wang
// Date: 2017-08-07
class Solution {
 public:
  TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
    return nums.empty() ? nullptr : MaxBT(nums, 0, nums.size() - 1);
  }

 private:
  TreeNode* MaxBT(const vector<int>& nums, int l, int r) const {
    if (l > r) return nullptr;
    int idx = l;
    for (int i = l + 1; i <= r; ++i)
      if (nums[i] > nums[idx])
        idx = i;
    TreeNode* root = new TreeNode(nums[idx]);
    root->left = MaxBT(nums, l, idx - 1);
    root->right = MaxBT(nums, idx + 1, r);
    return root;
  }
};
