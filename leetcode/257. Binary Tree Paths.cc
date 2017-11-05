// Copyright 2017 Qi Wang
// Date: 2017-11-05
// Please note that the solution on 2017-09-01 is somewhat funny :)
class Solution {
 public:
  vector<string> binaryTreePaths(TreeNode* root) {
    vector<string> result;
    CollectResult(root, "", &result);
    return result;
  }
 
 private:
  void CollectResult(TreeNode* root, string cur, vector<string>* result) const {
    if (root == nullptr) return;
    if (!cur.empty()) cur += "->";
    cur += to_string(root->val);
    if (root->left == nullptr && root->right == nullptr) {
      result->push_back(cur);
    } else {
      CollectResult(root->left, cur, result);
      CollectResult(root->right, cur, result);
    }
  }
};

// Date: 2017-09-01
class Solution {
 public:
  vector<string> binaryTreePaths(TreeNode* root) {
    if (root == nullptr) return {};
    vector<string> result;
    auto gather_result = [this, root, &result](TreeNode* child) {
      auto child_paths = binaryTreePaths(child);
      for (auto& path : child_paths) {
        result.push_back(to_string(root->val) + "->" + move(path));
      }
    };
    gather_result(root->left);
    gather_result(root->right);
    return !result.empty() ? result : vector<string>{to_string(root->val)};
  }
};

// Date: 2017-07-18
class Solution {
 public:
  vector<string> binaryTreePaths(TreeNode* root) {
    vector<string> result;
    if (nullptr != root) F(root, "", &result);
    return result;
  }

 private:
  void F(TreeNode* root, string str, vector<string>* result) const {
    str += !str.empty() ? "->" : "";
    str += to_string(root->val);
    if (nullptr == root->left && nullptr == root->right)
      result->push_back(str);
    if (nullptr != root->left)
      F(root->left, str, result);
    if (nullptr != root->right)
      F(root->right, str, result);
  }
};

// Date: 2016-12-24
class Solution {
 public:
  vector<string> binaryTreePaths(TreeNode* root) {
    if (!root) return vector<string>();
    vector<string> res;
    dfs(root, "", res);
    return res;
  }

 private:
  void dfs(TreeNode *root, string cur, vector<string>& res) {
    cur += to_string(root->val);
    // is leaf
    if (!root->left && !root->right) {
      res.push_back(cur);
    // non-leaf (internal node)
    } else {
      cur += "->";
      if (root->left) dfs(root->left, cur, res);
      if (root->right) dfs(root->right, cur, res);
    }
  }
};

// Date: 2015-08
class Solution 
{
public:
    vector<string> binaryTreePaths(TreeNode* root) 
    {
      string path;
      dfs(path, root);
      return ret;
    }

private:
  void dfs(string& pre_path, TreeNode* cur)
  {
    if (cur == nullptr)
    {
      return ;
    } else if (cur->left==nullptr && cur->right==nullptr)
    {
      ret.push_back(pre_path + int_to_string(cur->val));
    } else 
    {
      string cur_path = pre_path + int_to_string(cur->val) + "->";
      dfs(cur_path, cur->left);
      dfs(cur_path, cur->right);
    }
  }

  string int_to_string(int num)
  {
    stringstream ss;
    ss << num;
    return ss.str();
  }

  vector<string> ret;
};