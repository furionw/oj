// Copyright 2017 Qi Wang
// Date: 2017-06-08
class Solution {
 public:
  vector<double> averageOfLevels(TreeNode* root) {
    vector<pair<double, int>> record;
    Foo(root, 0, &record);
    vector<double> result;
    for (const auto& p : record)
      result.push_back(p.first / p.second);
    return result;
  }

 private:
  void Foo(TreeNode* root, int depth, vector<pair<double, int>>* result) const {
    if (root == nullptr) return;
    if (depth < result->size()) {
      (*result)[depth].first += root->val;
      (*result)[depth].second += 1;
    } else {
      result->emplace_back(root->val, 1);
    }
    Foo(root->left, depth + 1, result);
    Foo(root->right, depth + 1, result);
  }
};