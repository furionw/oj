class Solution 
{
public:
    bool isBalanced(TreeNode *root) 
    {
        if (root == NULL)
        {
        	return true;
        } else
        {
        	return isBalanced(root->left)
        		&& isBalanced(root->right)
        		&& abs(height(root->left) - height(root->right))<=1;
        }
    }
private:
	int height(TreeNode *node)
	{
		if (node == NULL)
		{
			return 0;
		} else
		{
			return max(height(node->left), height(node->right)) + 1;
		}
	}
};