// Copyright 2017 Qi Wang
// Date: 2017-10-24
class Solution {
 public:
  vector<string> binaryTreePaths(TreeNode * root) {
    if (root == nullptr) return {};
    vector<string> result;
    BinaryTreePaths(root, "", &result);
    return result;
  }

 private:
  void BinaryTreePaths(TreeNode* node, string str, vector<string>* result)
      const {
    if (node == nullptr) return;
    str = (str.empty() ? "" : str + "->") + to_string(node->val);
    if (node->left == nullptr && node->right == nullptr) {
      result->push_back(str);
    } else {
      BinaryTreePaths(node->left, str, result);
      BinaryTreePaths(node->right, str, result);
    }
  }
};