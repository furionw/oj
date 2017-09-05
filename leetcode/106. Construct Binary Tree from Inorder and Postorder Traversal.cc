// Copyright 2017 Qi Wang
// Date: 2017-09-04
// Case 1: [[1], [1]]
// Case 2: [[1, 2], [2, 1]]
class Solution {
 public:
  TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    if (inorder.empty() || postorder.size() != inorder.size()) return nullptr;
    return BuildTree(inorder, 0, inorder.size() - 1,
                     postorder, 0, postorder.size() - 1);
  }
 
 private:
  TreeNode* BuildTree(
      const vector<int>& inorder, int i1, int i2,
      const vector<int>& postorder, int j1, int j2) const {
    if (i1 > i2) return nullptr;
    auto* root = new TreeNode(postorder[j2]);
    int left_len = 0;
    while (inorder[i1 + left_len] != root->val) ++left_len;
    root->left = BuildTree(inorder, i1, i1 + left_len - 1,
                           postorder, j1, j1 + left_len - 1);
    root->right = BuildTree(inorder, i1 + left_len + 1, i2,
                            postorder, j1 + left_len, j2 - 1);
    return root;
  }
};

class Solution 
{
public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) 
    {
        in = inorder;
        post = postorder;
        return gao(0, inorder.size(), 0, postorder.size());
    }

private:
  TreeNode *gao(size_t in_begin, size_t in_end, size_t post_begin, size_t post_end)
  {  
    if (post_end==0 || in_begin==in_end)
    {
      return NULL;
    }
    TreeNode *node = new TreeNode(post[post_end-1]);
    size_t left_cnt = 0;
    for ( ; in_begin+left_cnt<in_end && in[in_begin+left_cnt]!=post[post_end-1];
      ++ left_cnt) {}
    node->left = gao(in_begin, in_begin+left_cnt, post_begin, post_begin+left_cnt);
    node->right = gao(in_begin+left_cnt+1, in_end, post_begin+left_cnt, post_end-1);
    return node;
  }

  vector<int> in;
  vector<int> post;
};