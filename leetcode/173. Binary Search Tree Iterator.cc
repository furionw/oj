// Copyright 2017 Qi Wang
// Date: 2017-11-12
class BSTIterator {
 public:
  BSTIterator(TreeNode *root) {
    PopulateStk(root);
  }
 
  bool hasNext() {
    return !stk_.empty();
  }
 
  int next() {
    if (stk_.empty()) return INT_MIN;
    auto node = stk_.top(); stk_.pop();
    int result = node->val;
    PopulateStk(node->right);
    return result;
  }
 
 private:
  void PopulateStk(TreeNode* root) {
    for (; root != nullptr; root = root->left) {
      stk_.push(root);
    }
  }
 
  stack<TreeNode*> stk_;
};

// Date: 2017-07-22
// The solution on 2016-12-08 is more concise.
class BSTIterator {
 public:
  BSTIterator(TreeNode *root) {
    for (; root != nullptr; root = root->left) {
      stk_.push(root);
    }
  }

  bool hasNext() {
    return !stk_.empty();
  }

  int next() {
    auto node = stk_.top(); stk_.pop();
    int result = node->val;
    for (node = node->right; node != nullptr; node = node->left) {
      stk_.push(node);
    }
    return result;
  }

 private:
  stack<TreeNode*> stk_;
};

// Refer to the solution in 2015-08
// Date: 2016-12-08
class BSTIterator {
 public:
  BSTIterator(TreeNode *root) {
    pushLeftDescedants(root);
  }

  /** @return whether we have a next smallest number */
  bool hasNext() {
    return !stk_.empty();
  }

  /** @return the next smallest number */
  int next() {
    auto node = stk_.top();
    stk_.pop();
    pushLeftDescedants(node->right);
    return node->val;
  }
 
 private:
  void pushLeftDescedants(TreeNode* node) {
    for (; node; node = node->left)
      stk_.push(node);
  }

  stack<TreeNode*> stk_;
};

// Date: 2015-08
class BSTIterator 
{
public:
    BSTIterator(TreeNode *root) 
    {
        for ( ; root != nullptr; root = root->left)
        {
            stk.push(root);
        }
    }

    /** @return whether we have a next smallest number */
    bool hasNext() 
    {
        return !stk.empty();
    }

    /** @return the next smallest number */
    int next() 
    {
        auto node = stk.top();
        int val = node->val;
        stk.pop();
        node = node->right;
        for ( ; node != nullptr; node = node->left)
        {
            stk.push(node);
        }
        return val;
    }

private:
    stack<TreeNode*> stk;
};
