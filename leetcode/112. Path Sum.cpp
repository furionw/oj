// Copyright 2016 Qi Wang
// Date: 2016-10-30
class Solution {
 public:
  bool hasPathSum(TreeNode* root, int sum) {
    return root == nullptr
        ? false
        : root->left == nullptr && root->right == nullptr
            ? root->val == sum
            : hasPathSum(root->left, sum - root->val)
                || hasPathSum(root->right, sum - root->val);
  }
};

// Date: 2014-08
class Solution 
{
public:
    bool hasPathSum(TreeNode *root, int sum) 
    {
    	if (root!=NULL && root->left==NULL && root->right==NULL && root->val==sum)
    	{
    		return true;
    	} else if (root!=NULL)
    	{
    		return hasPathSum(root->left, sum-root->val)
    			|| hasPathSum(root->right, sum-root->val);
    	} else
    	{
    		return false;
    	}
    }
};