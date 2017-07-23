// Copyright 2017 Qi Wang
// Date: 2017-07-22
class Solution {
 public:
  bool isValidBST(TreeNode* root) {
    if (root == nullptr) return true;
    pair<int, int> minmax {root->val, root->val};
    return IsValidBst(root, &minmax);
  }

 private:
  bool IsValidBst(TreeNode* root, pair<int, int>* minmax) const {
    auto update_minmax = [minmax](const pair<int, int>& p) {
      minmax->first = min(minmax->first, p.first);
      minmax->second = max(minmax->second, p.second);
    };
    if (root->left != nullptr) {
      pair<int, int> p {root->left->val, root->left->val};
      if  (!IsValidBst(root->left, &p) || p.second >= root->val) {
        return false;
      }
      update_minmax(p);
    }
    if (root->right != nullptr) {
      pair<int, int> p {root->right->val, root->right->val};
      if  (!IsValidBst(root->right, &p) || p.first <= root->val) {
        return false;
      }
      update_minmax(p);
    }
    return true;
  }
};

class Solution {
 public:
  bool isValidBST(TreeNode* root) {
    if (nullptr != root) {
      if (nullptr != root->left &&
          (!isValidBST(root->left) || gao(root->left).second >= root->val))
        return false;
      if (nullptr != root->right &&
          (!isValidBST(root->right) || gao(root->right).first <= root->val))
        return false;
    }
    return true;
  }
  
 private:
   pair<int, int> gao(TreeNode* node) {
    assert(nullptr != node);
    return make_pair(
      nullptr != node->left? gao(node->left).first: node->val,
      nullptr != node->right? gao(node->right).second: node->val);
   }
};

// Error: cannot handle the case [-2147483648,null,2147483647]
class Solution 
{
public:
    bool isValidBST(TreeNode *root) 
    {
      return gao(root, INT_MIN, INT_MAX);
    }

private:
  bool gao(TreeNode *node, int lower_bound, int upper_bound)
  {
    if (node==NULL || (node->left==NULL && node->right==NULL))
    {
      return true;
    } else if (node->left!=NULL && node->right!=NULL)
    {
      return node->left->val < node->val
        && node->left->val > lower_bound
        && node->right->val > node->val
        && node->right->val < upper_bound
        && gao(node->left, lower_bound, node->val)
        && gao(node->right, node->val, upper_bound);
    } else if (node->left==NULL && node->right!=NULL)
    {
      return node->right->val > node->val
        && node->right->val < upper_bound
        && gao(node->right, node->val, upper_bound);
    } else if (node->left!=NULL && node->right==NULL)
    {
      return node->left->val < node->val
        && node->left->val > lower_bound
        && gao(node->left, lower_bound, node->val);
    }
    return false;
  }
};
