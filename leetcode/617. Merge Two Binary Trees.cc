// Copyright 2017 Qi Wang
// Date: 2017-06-11
class Solution {
 public:
  TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
    if (nullptr != t1 && nullptr != t2) {
      t1->val += t2->val;
      t1->left = mergeTrees(t1->left, t2->left);
      t1->right = mergeTrees(t1->right, t2->right);
      return t1;
    } else {
      return nullptr != t1 ? t1 : t2;
    }
  }
};

// Date: 2017-06-11
class Solution {
 public:
  TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
    if (nullptr == t1 && nullptr == t2) {
      return nullptr;
    } else if (nullptr != t1 && nullptr == t2) {
      return t1;
    } else if (nullptr == t1 && nullptr != t2) {
      return t2;
    } else {
      t1->val += t2->val;
      t1->left = mergeTrees(t1->left, t2->left);
      t1->right = mergeTrees(t1->right, t2->right);
      return t1;
    }
  }
};
