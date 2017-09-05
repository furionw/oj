// Copyright 2017 Qi Wang
// Date: 2017-09-04
// Case 1: [[1, 2, 3], [2, 1, 3]]
class Solution {
 public:
  TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    if (preorder.empty() || preorder.size() != inorder.size()) return nullptr;
    return BuildTree(preorder, 0, preorder.size() - 1, inorder, 0);
  }
 
 private:
  TreeNode* BuildTree(
      const vector<int>& preorder, int i1, int i2,
      const vector<int>& inorder, int j1) const {
    if (i1 > i2) return nullptr;
    auto* root = new TreeNode(preorder[i1]);
    int len = 0;
    while (inorder[j1 + len] != preorder[i1]) ++len;
    if (len > 0) {
      root->left = BuildTree(preorder, i1 + 1, i1 + len, inorder, j1);
    }
    root->right = BuildTree(preorder, i1 + len + 1, i2, inorder, j1 + len + 1);
    return root;
  }
};

class Solution 
{
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) 
    {
      pre = preorder;
      in = inorder;
      return gao(0, preorder.size(), 0, inorder.size());
     }
private:
  TreeNode *gao(size_t pre_begin, size_t pre_end, size_t in_begin, size_t in_end)
  {
    if (pre_begin>=pre.size() || pre_begin==pre_end)
    {
      return NULL;
    }
    auto node = new TreeNode(pre[pre_begin]);
    size_t left_cnt = 0;
    for ( ; in_begin+left_cnt<in_end && in[in_begin+left_cnt]!=pre[pre_begin];
      ++ left_cnt) {}
    node->left = gao(pre_begin+1, pre_begin+1+left_cnt, in_begin, in_begin+left_cnt);
    node->right = gao(pre_begin+1+left_cnt, pre_end, in_begin+left_cnt+1, in_end);
    return node;
  }
  vector<int> pre;
  vector<int> in;
};
