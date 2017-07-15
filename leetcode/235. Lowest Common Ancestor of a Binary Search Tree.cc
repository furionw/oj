// Copyright 2017 Qi Wang
// Date: 2017-07-14
class Solution {
 public:
  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p,
      TreeNode* q) {
    return p->val < q->val ? F(root, p, q) : F(root, q, p);
  }

 private:
  TreeNode* F(TreeNode* root, TreeNode* p, TreeNode* q) const {
    if (p->val < root->val && root->val < q->val) {
      return root;
    } else if (q->val <= root->val) {
      return q->val == root->val ? q : F(root->left, p, q);
    } else {
      return p->val == root->val ? p : F(root->right, p, q);
    }
  }
};

// Date: 2016-09-30
class Solution {
 public:
  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    // Make sure p->val < q->val
    if (p->val >= q->val) swap(p, q);
    if (p->val < root->val && root->val < q->val) {
      // between [p->val, q->val]
      return root;
    } else if (root->val > q->val) {
      // greater than the largest q->val
      return lowestCommonAncestor(root->left, p, q);
    } else if (root->val < p->val) {
      // less than the smallest p->val
      return lowestCommonAncestor(root->right, p, q);
    } else {
      return root == p? p: q;
    }
  }
};
