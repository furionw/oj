// Copyright 2019 Qi Wang
// Date: 2019-03-02
// Refer to: https://leetcode.com/problems/maximum-binary-tree/discuss/106146/C%2B%2B-O(N)-solution
class Solution {
 public:
  TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
    if (nums.empty()) return nullptr;
    vector<TreeNode*> stk;
    for (int num: nums) {
      auto cur = new TreeNode(num);
      while (!stk.empty() && stk.back()->val < num) {
        cur->left = stk.back();
        stk.pop_back();
      }
      if (!stk.empty()) {
        stk.back()->right = cur;
      }
      stk.push_back(cur);
    }
    return stk[0];
  }
};

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
