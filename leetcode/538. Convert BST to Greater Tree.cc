// Copyright 2017 Qi Wang
// Date: 2017-04-25
// Method 3
// Refer to: https://discuss.leetcode.com/topic/83534/c-solution-beats-100
// God, it's a BST!!!
class Solution {
 public:
  TreeNode* convertBST(TreeNode* root) {
    int acc = 0;
    Traversal(root, acc);
    return root;
  }

 private:
  void Traversal(TreeNode* root, int& acc) const {
    if (nullptr == root) return;
    Traversal(root->right, acc);
    root->val = acc += root->val;
    Traversal(root->left, acc);
  }
};

// Date: 2017-04-25
// Method 2: toooooooooooooooooooooooooo slow
// Note that we should recycle the memory in this impl
class Solution {
 public:
  TreeNode* convertBST(TreeNode* root) {
    auto copy = Copy(root);
    Convert(copy, copy, root);
    return root;
  }

 private:
  TreeNode* Copy(TreeNode* root) const {
    if (nullptr == root) return nullptr;
    auto new_root = new TreeNode(root->val);
    new_root->left = Copy(root->left);
    new_root->right = Copy(root->right);
    return new_root;
  }

  void Convert(TreeNode* cur, TreeNode* root, TreeNode* result) const {
    if (nullptr == cur) return;
    Inc(cur, root, result);
    Convert(cur->left, root, result->left);
    Convert(cur->right, root, result->right);
  }

  void Inc(TreeNode* cur, TreeNode* root, TreeNode* result) const {
    if (nullptr == root) return;
    if (cur->val < root->val) result->val += root->val;
    Inc(cur, root->left, result);
    Inc(cur, root->right, result);
  }
};

// Date: 2017-04-25
// Method 1
class Solution {
 public:
  TreeNode* convertBST(TreeNode* root) {
    vector<int> nums;
    Traversal(root, nums);
    sort(nums.begin(), nums.end());
    auto sums = nums;
    for (size_t i = 1; i < sums.size(); ++i) sums[i] += sums[i - 1];
    Convert(root, nums, sums);
    return root;
  }

 private:
  void Traversal(TreeNode* root, vector<int>& nums) const {
    if (nullptr == root) return;
    nums.push_back(root->val);
    Traversal(root->left, nums);
    Traversal(root->right, nums);
  }

  void Convert(TreeNode* root, const vector<int>& nums,
      const vector<int>& sums) const {
    if (nullptr == root) return;
    auto greater = upper_bound(nums.begin(), nums.end(), root->val);
    if (nums.end() != greater)
      root->val += sums.back() - sums[distance(nums.begin(), greater)] +
          *greater;
    Convert(root->left, nums, sums);
    Convert(root->right, nums, sums);
  }
};
