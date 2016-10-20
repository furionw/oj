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