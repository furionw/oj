// Copyright 2017 Qi Wang
// Date: 2017-11-02
class Solution {
 public:
  bool isSubtree(TreeNode* s, TreeNode* t) {
    if (s != nullptr && t != nullptr) {
      return (s->val == t->val && Equals(s->left, t->left) &
              Equals(s->right, t->right)) ||
             isSubtree(s->left, t) ||
             isSubtree(s->right, t);
    } else {
      return s == nullptr && t == nullptr;
    }
  }
 
 private:
  bool Equals(TreeNode* s, TreeNode* t) const {
    if (s != nullptr && t != nullptr) {
      return s->val == t->val && Equals(s->left, t->left) &&
             Equals(s->right, t->right);
    } else {
      return s == nullptr && t == nullptr;
    }
  }
};

// Date: 2017-08-04
class Solution {
 public:
  bool isSubtree(TreeNode* s, TreeNode* t) {
    return Equal(s, t) ||
        (s != nullptr
            ? isSubtree(s->left, t) || isSubtree(s->right, t)
            : false);
  }
 
 private:
  bool Equal(TreeNode* s, TreeNode* t) const {
    if (s == t) {
      return true;
    } else if (s == nullptr || t == nullptr) {
      return false;
    } else {
      return s->val == t->val && Equal(s->left, t->left)
          && Equal(s->right, t->right);
    }
  }
};

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
