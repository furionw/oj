// Copyright 2016 Qi Wang
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
