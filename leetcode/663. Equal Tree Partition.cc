// Copyright 2017 Qi Wang
// Date: 2017-08-24
class Solution {
 public:
  bool checkEqualTree(TreeNode* root) {
    unordered_map<TreeNode*, int> node_to_acc_map;
    node_to_acc_map[nullptr] = 0;
    int acc = InitNodeToAccMap(root, &node_to_acc_map);
    return CheckEqualTree(root, acc, &node_to_acc_map);
  }
 
 private:
  int InitNodeToAccMap(
      TreeNode* root,
      unordered_map<TreeNode*, int>* node_to_acc_map) const {
    if (root == nullptr) return 0;
    int acc = root->val + InitNodeToAccMap(root->left, node_to_acc_map)
              + InitNodeToAccMap(root->right, node_to_acc_map);
    return (*node_to_acc_map)[root] = acc;
  }
 
  bool CheckEqualTree(
      TreeNode* root, int acc,
      unordered_map<TreeNode*, int>* node_to_acc_map) const {  
    if (root == nullptr) return false;
    return (root->left != nullptr &&
            (*node_to_acc_map)[root->left] * 2 == acc) ||
           (root->right != nullptr &&
            (*node_to_acc_map)[root->right] * 2 == acc) ||
           CheckEqualTree(root->left, acc, node_to_acc_map) ||
           CheckEqualTree(root->right, acc, node_to_acc_map);
  }
};
