// Copyright 2017 Qi Wang
// Date: 2016-11-27
// Last modified: 2017-01-03
class Codec {
 public:
  string serialize(TreeNode* root) {
    // trivial case
    if (!root) return string();
    // non trivial case
    string data;
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
      auto front = q.front();
      if (front != nullptr) {
        data += string(",") + to_string(front->val);
        // BFS
        q.push(front->left);
        q.push(front->right);
      } else {
        data += ",n";
      }
      q.pop();
    }
    // Elimiate the preceeding ","
    return data.substr(1);
  }
  
  TreeNode* deserialize(string data) {
    // trivial case
    if (data.empty()) return nullptr;
    // non trivial
    auto nodes = strToQ(data);
    auto root = nodes.front();
    queue<pair<TreeNode*, bool>> parents;
    parents.emplace(nodes.front(), false);
    nodes.pop();
    while (!nodes.empty()) {
      if (!parents.front().second) {
        parents.front().first->left = nodes.front();
        parents.front().second = true;
      } else {
        parents.front().first->right = nodes.front();
        parents.pop();
      }
      // non nullptr
      if (nodes.front() != nullptr) parents.emplace(nodes.front(), false);
      nodes.pop();
    }
    return root;
  }

 private:
  queue<TreeNode*> strToQ(const string& data) {
    queue<TreeNode*> q;
    for (size_t i = 0; i < data.size();) {
      // null
      if (data[i] == 'n') {
        q.push(nullptr);
        i += 2;
      // digits
      } else {
        size_t len = 1;
        while (i + len < data.size() && data[i + len] != ',') ++len;
        q.push(new TreeNode(stoi(data.substr(i, len))));
        i += len + 1;
      }
    }
    return q;
  }
};
