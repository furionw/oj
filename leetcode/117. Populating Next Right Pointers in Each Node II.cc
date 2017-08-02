// Copyright 2017 Qi Wang
// Date: 2017-08-01
class Solution {
 public:
  void connect(TreeLinkNode *root) {
    TreeLinkNode* cur = root;
    while (cur != nullptr) {
      TreeLinkNode *head = nullptr;
      for (TreeLinkNode *prev = nullptr; cur != nullptr; cur = cur->next) {
        if (cur->left != nullptr) {
          if (prev != nullptr) {
            prev->next = cur->left;
          } else {
            head = cur->left;
          }
          prev = cur->left;
        }
        if (cur->right != nullptr) {
          if (prev != nullptr) {
            prev->next = cur->right;
          } else {
            head = cur->right;
          }
          prev = cur->right;
        }
      }
      // Jump to the next level
      cur = head;
    }
  }
};

// Date: 2017-08-01
class Solution {
 public:
  void connect(TreeLinkNode *root) {
    if (root == nullptr) return;
    queue<TreeLinkNode*> nodes;
    nodes.push(root);
    nodes.push(nullptr);
    while (nodes.size() > 1) {
      queue<TreeLinkNode*> children;
      while (nodes.size() > 1) {
        auto node = nodes.front(); nodes.pop();
        node->next = nodes.front();
        if (node->left != nullptr) {
          children.push(node->left);
        }
        if (node->right != nullptr) {
          children.push(node->right);
        }
      }
      children.push(nullptr);
      nodes = move(children);
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