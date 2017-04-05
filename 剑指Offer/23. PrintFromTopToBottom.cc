// Copyright 2017 Qi Wang
// Date: 2017-04-04
class Solution {
 public:
  vector<int> PrintFromTopToBottom(TreeNode* root) {
    if (root == nullptr) return vector<int>();
    queue<TreeNode*> q;
    q.push(root);
    vector<int> result;
    while (!q.empty()) {
      root = q.front();
      q.pop();
      result.push_back(root->val);
      if (root->left != nullptr) q.push(root->left);
      if (root->right != nullptr) q.push(root->right);
    }
    return result;
  }
};
