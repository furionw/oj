// Copyright 2017 Qi Wang
// Date: 2017-02-05
// Morris traversal
class Solution {
 public:
  vector<int> inorderTraversal(TreeNode* root) {
    vector<int> result;
    TreeNode* cur = root;
    while (cur != nullptr) {
      if (cur->left == nullptr) {
        result.push_back(cur->val);
        cur = cur->right;
      } else {
        auto prev = cur->left;
        while (prev->right != nullptr && prev->right != cur)
          prev = prev->right;
        if (prev->right == nullptr) {
          prev->right = cur;
          cur = cur->left;
        // prev->right == cur
        } else {
          result.push_back(cur->val);
          prev->right = nullptr;
          cur = cur->right;
        }
      }
    }
    return result;
  }
};

// Date: ...
class Solution 
{
public:
    vector<int> inorderTraversal(TreeNode *root) 
    {
      vector<int> ret;
      gao(root, ret);
      return ret;
    }
private:
  void gao(TreeNode* node, vector<int>& ret)
  {
    if (node != NULL)
    {
      gao(node->left, ret);
      ret.push_back(node->val);
      gao(node->right, ret);
    }
  }
};
