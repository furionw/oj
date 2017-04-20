// Copyright 2017 Qi Wang
// Date: 2017-04-20
class Solution {
 public:
  vector<int> boundaryOfBinaryTree(TreeNode* root) {
    // trivial case
    if (nullptr == root) return vector<int>();
    // non-trivial case
    vector<int> result(1, root->val);
    // left boundary
    LeftBoundary(root->left, result);
    // inorder travesal. If root is a leaf also, it has been added to the result
    // before Inorder() call
    Inorder(root->left, result);
    Inorder(root->right, result);
    // right boundary
    RightBoundary(root->right, result);
    return result;
  }

 private:
  void LeftBoundary(TreeNode* root, vector<int>& result) const {
    if (nullptr == root) return;
    // non-leaf
    while (nullptr != root->left || nullptr != root->right) {
      result.push_back(root->val);
      root = nullptr != root->left ? root->left : root->right;
    }
  }

  void Inorder(TreeNode* root, vector<int>& result) const {
    if (nullptr == root) return;
    // left subtree
    Inorder(root->left, result);
    // leaf
    if (nullptr == root->left && nullptr == root->right)
      result.push_back(root->val);
    // right subtree
    Inorder(root->right, result);
  }

  void RightBoundary(TreeNode* root, vector<int>& result) const {
    if (nullptr == root) return;
    // non-leaf
    if (nullptr != root->left || nullptr != root->right) {
      RightBoundary(nullptr != root->right ? root->right : root->left, result);
      result.push_back(root->val);
    }
  }
};

