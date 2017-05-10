// Copyright 2017 Qi Wang
// Date: 2017-05-10
class Solution {
 public:
  bool isSubtree(TreeNode* s, TreeNode* t) {
    if (nullptr == s && nullptr == t) {
      return true;
    } else if (nullptr == s || nullptr == t) {
      return false;
    } else {
      return (s->val == t->val && Equal(s->left, t->left) && Equal(s->right,
          t->right)) || isSubtree(s->left, t) || isSubtree(s->right, t);
    }
  }

 private:
  bool Equal(TreeNode *s, TreeNode *t) const {
    if (nullptr == s && nullptr == t) {
      return true;
    } else if (nullptr == s || nullptr == t) {
      return false;
    } else {
      return s->val == t->val && Equal(s->left, t->left)
          && Equal(s->right, t->right);
    }
  }
};
