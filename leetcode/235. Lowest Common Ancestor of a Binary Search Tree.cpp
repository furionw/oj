// Copyright 2016 Stephen Wong
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
