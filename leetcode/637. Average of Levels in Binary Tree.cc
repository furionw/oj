// Copyright 2017 Qi Wang
// Date: 2017-08-05
class Solution {
 public:
  vector<double> averageOfLevels(TreeNode* root) {
    vector<pair<double, int>> acc;
    if (root != nullptr) {
      F(root, 0, &acc);
    }
    vector<double> result(acc.size());
    for (int i = 0; i < acc.size(); ++i) {
      result[i] = acc[i].first / acc[i].second;
    }
    return result;
  }
 
 private:
  void F(TreeNode* root, int lvl, vector<pair<double, int>>* acc) const {
    if (lvl == acc->size()) {
      acc->emplace_back(root->val, 1);
    } else {
      (*acc)[lvl].first += root->val;
      ++(*acc)[lvl].second;
    }
    if (root->left != nullptr) {
      F(root->left, lvl + 1, acc);
    }
    if (root->right != nullptr) {
      F(root->right, lvl + 1, acc);
    }
  }
};

// Date: 2017-07-08
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