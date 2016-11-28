// Copyright 2016 Qi Wang
// Method 2
// Conversion strategy between integer and string is designed and implemented
// on my own, while the preorder traversal solution is refer to:
//   - http://bookshadow.com/weblog/2016/11/01/leetcode-serialize-and-deserialize-bst/
// Date: 2016-11-28
class Codec {
 public:
  string serialize(TreeNode* root) {
    // trivial case
    if (!root) return "";
    // non trivial case
    string data;
    stack<TreeNode*> s;
    s.push(root);
    while (!s.empty()) {
      auto node = s.top();
      s.pop();
      data += intToStr(node->val);
      if (node->right) s.push(node->right);
      if (node->left) s.push(node->left);
    }
    return data;
  }
  
  TreeNode* deserialize(string data) {
    // trivial case
    if (data.empty()) return nullptr;
    // non trivial case
    vector<TreeNode*> nstack;
    stack<long long> rstack;
    nstack.push_back(new TreeNode(strToInt(data.substr(0, 4))));
    rstack.push(LLONG_MAX);
    for (size_t i = 4; i < data.size(); i += 4) {
      auto node = new TreeNode(strToInt(data.substr(i, 4)));
      if (node->val < nstack.back()->val) {
        nstack.back()->left = node;
        rstack.push(nstack.back()->val);
      } else {
        while (node->val > rstack.top()) {
          while (nstack.back()->val > nstack[nstack.size() - 2]->val)
            nstack.pop_back();
          nstack.pop_back();
          rstack.pop();
        }
        nstack.back()->right = node;
      }
      nstack.push_back(node);
    }
    return nstack.front();
  }

 private:
  inline int strToInt(const string& str) const {
    int val = 0;
    // val[7, ..., 0] = str[0]
    // val[15, ..., 8] = str[1]
    // val[23, ..., 16] = str[2]
    // val[31, ..., 25] = str[3]
    for (int i = 0; i < 4; ++i)
      // To execute shift operation E1 << E2, I think E1 will be converted to
      // result type first, which means if str[i] is signed char and representing
      // a nagetive integer, it will be extended with preceeding 1s, resulting in
      // a wrong answer here.
      val |= static_cast<uint8_t>(str[i]) << (i << 3);
    return val;
  }

  inline string intToStr(int val) const {
    string str(4, 0);
    // str[0] : val[7, ..., 0]
    // str[1] : val[15, ..., 8]
    // str[2] : val[24, ..., 16]
    // str[3] : val[31, ..., 25]
    for (int i = 0; i < 4; ++i)
      str[i] = val >> (i << 3);  // chopping
    return str;
  }
};

// Method 1
// Date: 2016-11-28
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
      if (front) {
        data += string(",") + to_string(front->val);
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
      if (nodes.front()) parents.emplace(nodes.front(), false);
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
