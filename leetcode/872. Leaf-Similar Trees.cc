// 2025-06-16
class Solution {
 public:
  bool leafSimilar(TreeNode* root1, TreeNode* root2) {
    // return leaves(root1) == leaves(roo2);
    vector<int> result1, result2;
    leaves(root1, result1);
    leaves(root2, result2);
    return result1 == result2;
  }

 private:
  void leaves(TreeNode* node, vector<int>& result) {
    if (node == nullptr) {
      return;
    }
    if (node->left == nullptr && node->right == nullptr) {
      result.push_back(node->val);
    }
    leaves(node->left, result);
    leaves(node->right, result);
  }
};
