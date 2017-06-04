// Copyright 2017 Qi Wang
// Date: 2017-06-04
// Refer to watashi's solution
class Solution {
 public:
  string tree2str(TreeNode* t) {
    string result;
    Foo(t, result);
    return result;
  }

 private:
  void Foo(TreeNode* t, string& result) const {
    if (nullptr != t) {
      result += to_string(t->val);
      if (nullptr != t->left || nullptr != t->right) {
        Bar(t->left, result);
        if (nullptr != t->right) Bar(t->right, result);
      }
    }
  }

  void Bar(TreeNode* t, string& result) const {
    result += '(';
    Foo(t, result);
    result += ')';
  }
};

// Date: 2017-06-04
class Solution {
 public:
  string tree2str(TreeNode* t) {
    if (nullptr == t) return "";
    return Foo(t);
  }

 private:
  string Foo(TreeNode* t) const {
    string result = to_string(t->val);
    if (nullptr == t->left && nullptr == t->right) {
      return result;
    // t->right is non-null
    } else if (nullptr == t->left) {
      result += "()";
      result += Bar(t->right);
    // t->left is non-null
    } else if (nullptr == t->right) {
      result += Bar(t->left);
    } else {
      result += Bar(t->left);
      result += Bar(t->right);
    }
    return result;
  }

  string Bar(TreeNode* t) const {
    string result = "(";
    return result + Foo(t) + ')';
  }
};
