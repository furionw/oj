// Copyright 2017 Qi Wang
// Date: 2017-04-23
class Solution {
 public:
  int longestConsecutive(TreeNode* root) {
    if (root == nullptr) return 0;
    int inc, des, terminal;
    F(root, inc, des, terminal);
    return max(inc, max(des, terminal));
  }

 private:
  void F(const TreeNode* root, int& inc, int& des, int& terminal) const {
    inc = des = terminal = 1;
    int leftInc, leftDes, leftTerminal, rightInc, rightDes, rightTerminal;
    if (root->left != nullptr) {
      F(root->left, leftInc, leftDes, leftTerminal);
      if (root->val == root->left->val + 1) inc = leftInc + 1;
      if (root->val == root->left->val - 1) des = leftDes + 1;
      terminal = max(inc, max(des, leftTerminal));
    }
    if (root->right != nullptr) {
      F(root->right, rightInc, rightDes, rightTerminal);
      if (root->val == root->right->val + 1) inc = max(inc, rightInc + 1);
      if (root->val == root->right->val - 1) des = max(des, rightDes + 1);
      terminal = max(terminal, max(inc, max(des, rightTerminal)));
    }
    if (root->left != nullptr && root->right != nullptr) {
      if (root->left->val + 1 == root->val && root->val + 1 == root->right->val)
        terminal = max(terminal, leftInc + 1 + rightDes);
      if (root->left->val - 1 == root->val && root->val - 1 == root->right->val)
        terminal = max(terminal, leftDes + 1 + rightInc);
    }
  }
};
