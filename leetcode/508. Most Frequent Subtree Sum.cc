// Copyright 2017 Qi Wang
// Date: 2017-02-07
class Solution {
 public:
  vector<int> findFrequentTreeSum(TreeNode* root) {
    if (root == nullptr) return vector<int>();
    unordered_map<int, int> cnts;
    f(root, cnts);
    vector<int> result;
    int freq = 0;
    for (const auto& p : cnts)
      if (p.second >= freq) {
        if (p.second > freq) {
          freq = p.second;
          result.clear();
        }
        result.push_back(p.first);
      }
    return result;
  }

 private:
  int f(TreeNode* root, unordered_map<int, int>& cnts) const {
    int sum = root->val;
    if (root->left != nullptr) sum += f(root->left, cnts);
    if (root->right != nullptr) sum += f(root->right, cnts);
    ++cnts[sum];
    return sum;
  }
};
