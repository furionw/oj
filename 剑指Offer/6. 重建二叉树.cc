// Copyright 2017 Qi Wang
// Date: 2017-09-04
// LeetCode 105
// Case 1: [[1, 2, 3], [2, 1, 3]]
class Solution {
 public:
  TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    if (preorder.empty() || preorder.size() != inorder.size()) return nullptr;
    return BuildTree(preorder, 0, preorder.size() - 1, inorder, 0);
  }
 
 private:
  TreeNode* BuildTree(
      const vector<int>& preorder, int i1, int i2,
      const vector<int>& inorder, int j1) const {
    if (i1 > i2) return nullptr;
    auto* root = new TreeNode(preorder[i1]);
    int len = 0;
    while (inorder[j1 + len] != preorder[i1]) ++len;
    if (len > 0) {
      root->left = BuildTree(preorder, i1 + 1, i1 + len, inorder, j1);
    }
    root->right = BuildTree(preorder, i1 + len + 1, i2, inorder, j1 + len + 1);
    return root;
  }
};

// Date: 2017-09-04
// Case 1: [[1], [1]]
// Case 2: [[1, 2], [2, 1]]
// LeetCode 106
class Solution {
 public:
  TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    if (inorder.empty() || postorder.size() != inorder.size()) return nullptr;
    return BuildTree(inorder, 0, inorder.size() - 1,
                     postorder, 0, postorder.size() - 1);
  }
 
 private:
  TreeNode* BuildTree(
      const vector<int>& inorder, int i1, int i2,
      const vector<int>& postorder, int j1, int j2) const {
    if (i1 > i2) return nullptr;
    auto* root = new TreeNode(postorder[j2]);
    int left_len = 0;
    while (inorder[i1 + left_len] != root->val) ++left_len;
    root->left = BuildTree(inorder, i1, i1 + left_len - 1,
                           postorder, j1, j1 + left_len - 1);
    root->right = BuildTree(inorder, i1 + left_len + 1, i2,
                            postorder, j1 + left_len, j2 - 1);
    return root;
  }
};
