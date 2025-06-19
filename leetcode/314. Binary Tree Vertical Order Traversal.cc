// 2025-06-18
class Solution {
 public:
  vector<vector<int>> verticalOrder(TreeNode* root) {
    if (root == nullptr) {
      return {};
    }
    int l = 0, r = 0; 
    exploreBoundary(root, 0 /*cur*/, l, r);

    vector<vector<int>> result(r - l + 1, vector<int>{});
    queue<pair<TreeNode*, int>> q;
    q.emplace(root, 0 /*cur*/);
    while (!q.empty()) {
      auto [node, cur] = q.front();
      q.pop();
      result[cur - l].push_back(node->val);
      if (node->left != nullptr) {
        q.emplace(node->left, cur - 1);
      }
      if (node->right != nullptr) {
        q.emplace(node->right, cur + 1);
      }
    }

    return result;
  }

 private:
  void exploreBoundary(TreeNode* node, int cur, int& l, int& r) {
    if (node == nullptr) {
      return;
    }
    l = min(l, cur);
    r = max(r, cur);
    exploreBoundary(node->left, cur - 1, l, r);
    exploreBoundary(node->right, cur + 1, l, r);
  }
};


// Date: 2017-10-31
class Solution {
 public:
  vector<vector<int>> verticalOrder(TreeNode* root) {
    if (root == nullptr) return {};
    int min_idx = 0, max_idx = 0;
    queue<pair<int, TreeNode*>> q;
    q.emplace(0, root);
    unordered_map<int, vector<int>> idx_to_vt_map;
    while (!q.empty()) {
      auto front = q.front(); q.pop();
      idx_to_vt_map[front.first].push_back(front.second->val);
      min_idx = min(min_idx, front.first);
      max_idx = max(max_idx, front.first);
      if (front.second->left != nullptr) {
        q.emplace(front.first - 1, front.second->left);
      }
      if (front.second->right != nullptr) {
        q.emplace(front.first + 1, front.second->right);
      }
    }
    vector<vector<int>> result(max_idx - min_idx + 1);
    for (auto& p : idx_to_vt_map) {
      // Uses subtraction operator here!!!
      result[p.first - min_idx] = move(p.second);
    }
    return result;
  }
};

// Date: 2017-08-28
// Method 2: without using unordered_map
class Solution {
 public:
  vector<vector<int>> verticalOrder(TreeNode* root) {
    if (root == nullptr) return {};
    // <offset, node>
    int min_offset = 0, max_offset = 0;
    GetRange(root, 0, &min_offset, &max_offset);
    vector<vector<int>> result(max_offset - min_offset + 1);
    queue<pair<int, TreeNode*>> q;
    q.emplace(0, root);
    while (!q.empty()) {
      const auto& front = q.front();
      result[front.first - min_offset].push_back(front.second->val);
      if (front.second->left != nullptr)
        q.emplace(front.first - 1, front.second->left);
      if (front.second->right != nullptr)
        q.emplace(front.first + 1, front.second->right);
      q.pop();
    }
    return result;
  }

 private:
  void GetRange(TreeNode* root, int offset, int* min_offset,
                int* max_offset) const {
    (*min_offset) = min(*min_offset, offset);
    (*max_offset) = max(*max_offset, offset);
    if (root->left != nullptr)
      GetRange(root->left, offset - 1, min_offset, max_offset);
    if (root->right != nullptr)
      GetRange(root->right, offset + 1, min_offset, max_offset);
  }
};

// Date: 2017-08-28
// Method 1: using unordered_map
class Solution {
 public:
  vector<vector<int>> verticalOrder(TreeNode* root) {
    unordered_map<int, vector<int>> offset_to_vec_map;
    if (root == nullptr) return {};
    // <offset, node>
    queue<pair<int, TreeNode*>> q;
    q.emplace(0, root);
    int min_offset = 0, max_offset = 0;
    while (!q.empty()) {
      const auto& front = q.front();
      min_offset = min(min_offset, front.first);
      max_offset = max(max_offset, front.first);
      offset_to_vec_map[front.first].push_back(front.second->val);
      if (front.second->left != nullptr)
        q.emplace(front.first - 1, front.second->left);
      if (front.second->right != nullptr)
        q.emplace(front.first + 1, front.second->right);
      q.pop();
    }
    vector<vector<int>> result(max_offset - min_offset + 1);
    int offset = -min_offset;
    for (auto& p : offset_to_vec_map) {
      result[p.first + offset] = move(p.second);
    }
    return result;
  }
};

// Date: 2017-07-04
class Solution {
 public:
  vector<vector<int>> verticalOrder(TreeNode* root) {
    if (nullptr == root) return {};
    map<int, vector<int>> d;
    queue<pair<int, TreeNode*>> q;
    q.emplace(0, root);
    while (!q.empty()) {
      auto elem = q.front(); q.pop();
      d[elem.first].push_back(elem.second->val);
      if (nullptr != elem.second->left)
        q.emplace(elem.first - 1, elem.second->left);
      if (nullptr != elem.second->right)
        q.emplace(elem.first + 1, elem.second->right);
    }
    vector<vector<int>> result;
    for (auto& p : d)
      result.push_back(move(p.second));
    return result;
  }
};

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
