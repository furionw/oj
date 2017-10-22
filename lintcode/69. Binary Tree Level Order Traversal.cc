// Copyright 2017 Qi Wang
// Date: 2017-10-21
class Solution {
 public:
  vector<vector<int>> levelOrder(TreeNode * root) {
    vector<vector<int>> result;
    LevelOrder(root, &result, 0);
    return result;
  }
 
 private:
  void LevelOrder(TreeNode* root, vector<vector<int>>* result, int lvl) const {
    if (root == nullptr) return;
    if (lvl == result->size()) {
      result->push_back({root->val});
    } else {
      (*result)[lvl].push_back(root->val);
    }
    LevelOrder(root->left, result, lvl + 1);
    LevelOrder(root->right, result, lvl + 1);
  }
};
