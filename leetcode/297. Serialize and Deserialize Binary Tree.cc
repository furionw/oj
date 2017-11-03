// Copyright 2017 Qi Wang
// Date: 2017-11-02
class Codec {
 public:
  string serialize(TreeNode* root) {
    return root == nullptr
        ? "n"
        : to_string(root->val) + ',' + serialize(root->left) + ',' +
          serialize(root->right);
  }
  
  TreeNode* deserialize(string data) {
    int idx = 0;
    return Deserialize(data, &idx);
  }

 private:
  TreeNode* Deserialize(const string& data, int* idx) const {
    if (data[*idx] == 'n') {
      *idx += 2;
      return nullptr;
    } else {
      int begin = *idx, len = 1;
      while (*idx + len < data.size() && IsDigit(data[*idx + len])) {
        ++len;
      }
      TreeNode* node = new TreeNode(stoi(data.substr(*idx, len)));
      *idx += len + 1;
      node->left = Deserialize(data, idx);
      node->right = Deserialize(data, idx);
      return node;
    }
  }

  bool IsDigit(char c) const {
    return '0' <= c && c <= '9';
  }
};

// Date: 2017-07-10
class Codec {
 public:
  string serialize(TreeNode* root) {
    return nullptr == root
        ? "n"
        : to_string(root->val) + "," + serialize(root->left) + "," +
              serialize(root->right);
  }

  TreeNode* deserialize(string data) {
    return Deserialize(&data.data());
  }

 private:
  TreeNode* Deserialize(const char** p) const {
    if ('n' == **p) {
      *p += 2;
      return nullptr;
    } else {
      const char* q = *p;
      while (IsDigit(*q) || '-' == *q) {
        ++q;
      }
      auto result = new TreeNode(atoi(*p));
      if (',' == *q) {
        *p = q + 1;
        result->left = Deserialize(p);
        result->right = Deserialize(p);
      }
      return result;
    }
  }

  bool IsDigit(char c) const {
    return '0' <= c && c <= '9';
  }
};

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
