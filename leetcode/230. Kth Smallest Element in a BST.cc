// Copyright 2016 Qi Wang
// Date: 2016-12-30
// Refer to the Top Solutions
class Solution {
 public:
  int kthSmallest(TreeNode* root, int k) {
    return f(root, k);
  }

 private:
  int f(TreeNode* root, int& k) const {
    if (root != nullptr) {
      int x = f(root->left, k);
      printf("%d\n", k);
      return k == 0 ? x : (--k == 0 ? root->val : f(root->right, k));
    }
    return 1;  // comfort the compiler
  }
};

// Date: 2016-10-31
class Solution {
 public:
  int kthSmallest(TreeNode* root, int k) {
    inorder(root, k);
    return res;
  }
 private:
  void inorder(TreeNode *root, int& k) {
    if (root->left) inorder(root->left, k);
    if (--k == 0) res = root->val;
    if (root->right) inorder(root->right, k);
  }

  int res;
};
