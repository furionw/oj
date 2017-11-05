// Copyright 2017 Qi Wang
// Date: 2017-11-05
// Case 1: [2, 1, 3]
class Solution {
 public:
  bool isValidBST(TreeNode* root) {
    return root == nullptr ? true : IsValidBST(root).valid;
  }
 
 private:
  struct MinMax {
    bool valid;
    int min, max;
  };
 
  MinMax IsValidBST(TreeNode* root) const {
    MinMax result {true, root->val, root->val};
    if (root->left != nullptr) {
      auto left = IsValidBST(root->left);
      if (left.valid && left.max < root->val) {
        result.min = left.min;
      } else {
        return {false};
      }
    }
    if (root->right != nullptr) {
      auto right = IsValidBST(root->right);
      if (right.valid && right.min > root->val) {
        result.max = right.max;
      } else {
        return {false};
      }
    }
    return result;
  }
};

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
