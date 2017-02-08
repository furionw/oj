// Copyright 2017 Qi Wang
// Date: 2017-02-05
// Method 2
class Solution {
 public:
  vector<int> findMode(TreeNode* root) {
    if (root == nullptr) return vector<int>();
    int max_mode = 0, cur_mode = 0, cur_val = 0;
    inorder(root, cur_val, cur_mode, max_mode);
    cur_val = 0, cur_mode = 0;
    vector<int> result;
    inorder(root, cur_val, cur_mode, max_mode, result);
    return result;
  }

 private:
  void inorder(TreeNode* root, int& cur_val, int& cur_mode, int& max_mode)
      const {
    if (root->left != nullptr)
      inorder(root->left, cur_val, cur_mode, max_mode);
    if (root->val != cur_val) {
      cur_val = root->val;
      cur_mode = 0;
    }
    max_mode = max(max_mode, ++cur_mode);
    if (root->right != nullptr)
      inorder(root->right, cur_val, cur_mode, max_mode);
  }

  void inorder(TreeNode* root, int& cur_val, int& cur_mode, const int max_mode,
      vector<int>& result) const {
    if (root->left != nullptr)
      inorder(root->left, cur_val, cur_mode, max_mode, result);
    if (root->val != cur_val) {
      cur_val = root->val;
      cur_mode = 0;
    }
    if (++cur_mode == max_mode)
      result.push_back(cur_val);
    if (root->right != nullptr)
      inorder(root->right, cur_val, cur_mode, max_mode, result);
  }
};

// Date: 2017-02-03
// Method 1
class Solution {
 public:
  vector<int> findMode(TreeNode* root) {
    unordered_map<int, int> cnts;
    findNode(root, cnts);
    vector<int> result;
    int cnt = 0;
    for (const auto& p: cnts) {
      if (p.second >= cnt) {
        if (p.second > cnt) result.clear();
        cnt = p.second;
        result.push_back(p.first);
      }      
    }
    return result;
  }

 private:
  void findNode(TreeNode* root, unordered_map<int, int>& cnts) const {
    if (root == nullptr) return;
    ++cnts[root->val];
    findNode(root->left, cnts);
    findNode(root->right, cnts);
  }
};
