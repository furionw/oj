// Copyright 2017 Qi Wang
// Date: 2017-11-07
// Refer to the method 2 on 2017-08-15
class Solution {
 public:
  TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
    if (root == nullptr || p == nullptr) {
      return nullptr;
    } else if (root->val <= p->val) {
      return inorderSuccessor(root->right, p);
    } else {
      auto left = inorderSuccessor(root->left, p);
      return left != nullptr ? left : root;
    }
  }
};

// Date: 2017-08-15
// Method 2: refer to other's solution
class Solution {
 public:
  TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
    if (p == nullptr || root == nullptr) {
      return nullptr;
    } else if (root->val <= p->val) {
      return inorderSuccessor(root->right, p);
    } else {
      auto left = inorderSuccessor(root->left, p);
      return left != nullptr ? left : root;
    }
  }
};

// Date: 2017-08-15
// Method 1: it's not a good solution
class Solution {
 public:
  TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
    bool found_p = false;
    return InorderSuccessor(root, p, &found_p);
  }

  TreeNode* InorderSuccessor(TreeNode* root, TreeNode* p,
      bool* found_p) const {
    if (root == nullptr) return nullptr;
    auto left = InorderSuccessor(root->left, p, found_p);
    if (left != nullptr) return left;
    if (*found_p) return root;
    *found_p = root->val == p->val;
    return InorderSuccessor(root->right, p, found_p);
  }
};

// Date: 2017-07-18
class Solution {
 public:
  TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
    TreeNode* candidate = nullptr;
    return F(root, p, candidate);
  }

 private:
  TreeNode* F(TreeNode* root, TreeNode* target, TreeNode* candidate) const {
    if (root == target) {
      TreeNode* result = Leftmost(root->right);
      return nullptr != result ? result : candidate;
    } else if (root->val > target->val) {
      return F(root->left, target, root);
    } else {
      return F(root->right, target, candidate);
    }
  }

  TreeNode* Leftmost(TreeNode* root) const {
    if (nullptr == root) return nullptr;
    for (; nullptr != root->left; root = root->left) {}
    return root;
  }
};
