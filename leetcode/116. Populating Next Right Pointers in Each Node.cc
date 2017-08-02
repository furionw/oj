// Copyright 2017 Qi Wang
// Date: 2017-08-01
class Solution {
 public:
  void connect(TreeLinkNode *root) {
    if (root != nullptr) {
      Connect(root, nullptr);
    }
  }

 private:
  void Connect(TreeLinkNode *root, TreeLinkNode *right) {
    root->next = right;
    if (root->left != nullptr) {
      Connect(root->left, root->right);
      Connect(root->right, right != nullptr ? right->left : nullptr);
    }
  }
};

class Solution 
{
public:
    void connect(TreeLinkNode *root) 
    {
      queue<TreeLinkNode*> nodes;
      queue<TreeLinkNode*> children;
      nodes.push(root);
      nodes.push(NULL);
      while ( nodes.front() != NULL )
      {
        auto cur = nodes.front();
        nodes.pop();
        cur->next = nodes.front();
        if (cur->left != NULL)
         {
           children.push( cur->left );
         }
         if (cur->right != NULL)
        {
             children.push( cur->right );
         }
         if (nodes.front() == NULL)
         {
          nodes = children;
          nodes.push(NULL);
          while (children.empty() == false)
          {
            children.pop();
          }
        }
      }
    }
};