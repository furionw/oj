class Solution 
{
public:
    int sumNumbers(TreeNode *root) 
    {   	
    	ret = 0;
    	foo(root, 0);
    	return ret;
    }
    
private:
	void foo(TreeNode* node, int num)
	{
		if (node == NULL)
		{
			return ;
		} else if (node->left==NULL && node->right==NULL)
		{
			ret = ret + (10*num+node->val);
		} else 
		{
			foo(node->left, 10*num+node->val);
			foo(node->right, 10*num+node->val);
		}
	}
	int ret;
};