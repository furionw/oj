// Date: 2022-10-20
// Method 2: BFS
// Refer to: https://leetcode.com/problems/reverse-odd-levels-of-binary-tree/discuss/2590049/C%2B%2B-or-Use-BFS-or-Simple-and-Efficient-approach
class Solution {
 public:
  TreeNode* reverseOddLevels(TreeNode* root) {
    queue<TreeNode*> q;
    vector<int> vals;
    int lvl = 0;
    q.push(root);
    vals.push_back(root->val);
    for (int lvl = 0; !q.empty(); ++lvl) {
      vector<int> next;
      for (size_t i = 0; i < vals.size(); ++i) {
        auto node = q.front();
        q.pop();
        if (lvl & 1) {
          node->val = vals[vals.size() - i - 1];
        }
        if (node->left != nullptr) {
          q.push(node->left);
          q.push(node->right);
          next.push_back(node->left->val);
          next.push_back(node->right->val);
        }
      }
      vals = next;
    }
    return root;
  }
};

// Method 1: DFS
class Solution {
 public:
  TreeNode* reverseOddLevels(TreeNode* root) {
    build(root, 1 /*level*/);
    modify(root, 1 /*level*/);
    return root;
  }
  
 private:
  void build(TreeNode* root, int level) {
    if (root == nullptr) {
      return;
    }
    valsByLvl[level].push_back(root->val);
    build(root->left, ++level);
    build(root->right, level);
  }

  void modify(TreeNode* root, int level) {
    if (root == nullptr) {
      return;
    }
    if ((level & 1) && root->left != nullptr) {
      auto& vals = valsByLvl[level + 1];
      root->left->val = vals.back();
      vals.pop_back();
      root->right->val = vals.back();
      vals.pop_back();
    }
    modify(root->left, ++level);
    modify(root->right, level);
  }
  
  unordered_map<int, vector<int>> valsByLvl;
};
