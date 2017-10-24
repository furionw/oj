// Copyright 2017 Qi Wang
// Date: 2017-10-23
// Method 1: O(lgh) space complexity
class BSTIterator {
 public:
  BSTIterator(TreeNode * root) {
    PopulateStack(root);
  }
 
  bool hasNext() {
    return !stk_.empty();
  }
 
  TreeNode * next() {
    auto* next = stk_.top(); stk_.pop();
    PopulateStack(next->right);
    return next;
  }
 
 private:
  void PopulateStack(TreeNode* node) {
    for (; node != nullptr; node = node->left) {
      stk_.push(node);
    }
  }
 
  stack<TreeNode*> stk_;
};
