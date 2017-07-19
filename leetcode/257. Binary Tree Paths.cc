// Copyright 2017 Qi Wang
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