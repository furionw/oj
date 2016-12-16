// Copyright 2016 Qi Wang
// Date: 2016-12-16
class Solution {
 public:
  // It's guaranteed that root != nullptr
  int maxPathSum(TreeNode* root) {
    // mps : maximal path sum
    int mps = INT_MIN;
    maxPathSum(root, mps);
    return mps;
  }

 private:
  // root : non nullptr
  int maxPathSum(TreeNode *root, int& mps) {
    // use question expression here to reduce the depth of recursive calls
    int lRes = root->left ? maxPathSum(root->left, mps) : 0;
    int rRes = root->right ? maxPathSum(root->right, mps) : 0;
    // res : the return value
    int res = max(0, max(lRes, rRes)) + root->val;
    mps = max(mps, max(res, lRes + root->val + rRes));
    return res;
  }
};

// Date: 2014-09
class Solution 
{
public:
    int maxPathSum(TreeNode *root) 
    {
        m_ret = INT_MIN;

        int val = root->val;
        if (root->left != NULL)
        {
            int left = single_side(root->left);
            val += (left>0? left: 0);
        }
        if (root->right != NULL)
        {
            int right = single_side(root->right);
            val += (right>0? right: 0);
        }

        return max(val, m_ret);
    }   
private:
    int m_ret;

    int single_side(TreeNode *node)
    {
        int val = node->val;

        if (node->left!=NULL && node->right!=NULL)
        {
            int left = single_side(node->left);
            int right = single_side(node->right);
            m_ret = max(m_ret, val+left+right);
            int larger = max(left, right);
            val += (larger>0? larger: 0);
        } else if (node->left != NULL)
        {
            int left = single_side(node->left);
            val += (left>0? left: 0);            
        } else if (node->right != NULL)
        {
            int right = single_side(node->right);
            val += (right>0? right: 0);
        }
        m_ret = max(m_ret, val);

        return val;
    }
};
