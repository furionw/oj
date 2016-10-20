class Solution 
{
public:
    bool isSymmetric(TreeNode *root) 
    {
    	 if (root == NULL)
    	 {
    	 	return true;
    	 } else
    	 {
    	 	return gao(root->left, root->right);
    	 }
    }

private:
	bool gao(TreeNode *left, TreeNode *right)
	{
		if (left!=NULL && right!=NULL)
		{
			return left->val == right->val
				&& gao(left->left, right->right)
				&& gao(left->right, right->left);
		} else if (left==NULL && right==NULL)
		{
			return true;
		} else
		{
			return false;
		}
	}
};