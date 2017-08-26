// Copyright 2017 Qi Wang
// Date: 2017-08-24
class Solution {
 public:
  int widthOfBinaryTree(TreeNode* root) {
    if (root == nullptr) return 0;
    vector<pair<int, int>> width_vec;
    F(root, 0, 0, &width_vec);
    int result = 0;
    for (const auto& p : width_vec) {
      result = max(result, p.second - p.first + 1);
    }
    return result;
  }
 
 private:
  void F(const TreeNode* root, int depth, int offset,
      vector<pair<int, int>>* width_vec) const {
    if (depth == width_vec->size()) {
      width_vec->emplace_back(offset, offset);
    } else {
      (*width_vec)[depth].first = min((*width_vec)[depth].first, offset);
      (*width_vec)[depth].second = max((*width_vec)[depth].second, offset);
    }
    if (root->left != nullptr)
      F(root->left, depth + 1, offset * 2, width_vec);
    if (root->right != nullptr)
      F(root->right, depth + 1, offset * 2 + 1, width_vec);
  }
};
