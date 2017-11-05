// Copyright 2017 Qi Wang
// Date: 2017-11-05
// Similar to LC 98. Validate Binary Search Tree
class Solution {
 public:
  int largestBSTSubtree(TreeNode* root) {
    if (root == nullptr) return 0;
    int max_sz = 1;
    LargestBSTSubtree(root, &max_sz);
    return max_sz;
  }
 
 private:
  struct Record {
    bool valid;
    int min, max, size;
  };
 
  Record LargestBSTSubtree(TreeNode* root, int* max_sz) const {
    Record result {true, root->val, root->val, 1};
    if (root->left != nullptr) {
      auto left = LargestBSTSubtree(root->left, max_sz);
      if (left.valid && left.max < root->val) {
        result.min = left.min;
        result.size += left.size;
      } else {
        result.valid = false;
      }
    }
    if (root->right != nullptr) {
      auto right = LargestBSTSubtree(root->right, max_sz);
      if (right.valid && right.min > root->val) {
        result.max = right.max;
        result.size += right.size;
      } else {
        result.valid = false;
      }
    }
    if (result.valid) *max_sz = max(*max_sz, result.size);
    return result;
  }
};
