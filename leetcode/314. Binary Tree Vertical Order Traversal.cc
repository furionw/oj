// Copyright 2016 Qi Wang
// Date: 2016-12-24
// Method 2: map, even slow than using list
// It looks like it's better to using list and maintaining the order on your own,
// rather than using map when the data size is small
class Solution {
 public:
  vector<vector<int>> verticalOrder(TreeNode* root) {
    vector<vector<int>> res;
    if (!root) return res;
    map<int, vector<int>> cols;
    queue<pair<int, TreeNode*>> q;
    q.emplace(0, root);
    while (!q.empty()) {
      auto p = q.front();
      q.pop();
      cols[p.first].push_back(p.second->val);
      if (p.second->left) q.emplace(p.first - 1, p.second->left);
      if (p.second->right) q.emplace(p.first + 1, p.second->right);
    }
    for (auto& col : cols)
      res.push_back(move(col.second));
    return res;
  }
};

// Date: 2016-12-24
// Method 1: with list
class Solution {
 private:
  struct Node {
    Node(int i, TreeNode *r) : root(r), idx(i) {}
    int idx;
    TreeNode *root;
  };

  struct Column {
    Column() {}
    Column(int i, int val) : idx(i), vals(vector<int>(1, val)) {}
    int idx;
    vector<int> vals;
  };

 public:
  vector<vector<int>> verticalOrder(TreeNode* root) {
    vector<vector<int>> res;
    if (!root) return res;
    // consider using map<pair<int, TreeNode*>>
    list<Column> cols;
    queue<Node> q;
    q.emplace(0, root);
    while (!q.empty()) {
      auto elem = q.front();
      q.pop();
      auto it = cols.begin();
      for (; it != cols.end() && it->idx < elem.idx; ++it) {}
      if (it != cols.end() && it->idx == elem.idx) {
        it->vals.push_back(elem.root->val);
      } else {
        cols.emplace(it, elem.idx, elem.root->val);
      }
      if (elem.root->left) q.emplace(elem.idx - 1, elem.root->left);
      if (elem.root->right) q.emplace(elem.idx + 1, elem.root->right);
    }
    for (auto& col : cols)
      res.push_back(move(col.vals));
    return res;
  }
};
