// Copyright 2017 Qi Wang
// Date: 2017-08-07
class Solution {
 public:
  // root is non-null
  vector<vector<string>> printTree(TreeNode* root) {
    int height = GetHeight(root);
    int width = 1;
    for (int i = 1; i < height; ++i) width = 2 * width + 1;
    vector<vector<string>> result(height, vector<string>(width, ""));
    Print(root, 0, 0, width - 1, &result);
    return result;
  }

 private:
  int GetHeight(TreeNode* root) const {
    return root == nullptr
        ? 0
        : 1 + max(GetHeight(root->left), GetHeight(root->right));
  }

  // root is non-null
  void Print(TreeNode* root, int height, int l, int r,
             vector<vector<string>>* result) const {
    int mid = (l + r) >> 1;
    (*result)[height][mid] = to_string(root->val);
    if (root->left != nullptr)
      Print(root->left, height + 1, l, mid - 1, result);
    if (root->right != nullptr)
      Print(root->right, height + 1, mid + 1, r, result);
  }
};
