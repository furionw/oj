// Copyright 2016 Qi Wang
// Reference: http://www.jianshu.com/p/118dfcb1d606
// Date: 2016-10-09
class Solution {
 public:
  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (root == nullptr || root == p || root == q) return root;
    auto left = lowestCommonAncestor(root->left, p, q);
    auto right = lowestCommonAncestor(root->right, p, q);
    if (left != nullptr && right != nullptr) {
      return root;
    } else if (left != nullptr) {
      return left;
    } else {
      return right;
    }
  }
};

// Copyright 2016 Qi Wang
// Date: 2016-10-09
class Solution {
 public:
  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    return lca(root, p, q).second;
  }

 private:
  pair<bool, TreeNode*> lca(TreeNode* node, TreeNode* p, TreeNode* q) {
    if (node == nullptr) {
      return make_pair(false, nullptr);
    } else if (node == p || node == q) {
      auto lhs = lca(node->left, p, q);
      auto rhs = lca(node->right, p, q);
      return make_pair(lhs.second == p || lhs.second == q || rhs.second == p ||
          rhs.second == q, node);
    } else {
      auto lhs = lca(node->left, p, q);
      auto rhs = lca(node->right, p, q);
      if (lhs.first || rhs.first) {
        return lhs.first ? lhs: rhs;
      } else if (lhs.second != nullptr && rhs.second != nullptr) {
        return make_pair(true, node);
      } else if (lhs.second != nullptr || rhs.second != nullptr) {
        return make_pair(false, lhs.second != nullptr ? lhs.second : rhs.second);
      } else {
        return make_pair(false, nullptr);
      }
    }
  }
};

