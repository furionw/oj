class Solution 
{
public:
    void flatten(TreeNode *root) 
    {
        if (root == NULL)
        {
        	return ;
        }
        flatten( root->left );
		flatten( root->right );        
        auto left_right_most = find_right_most(root->left);
        if (left_right_most != NULL)
        {
        	left_right_most->right = root->right;
        	root->right = root->left;
        	root->left = NULL;
        }
    }
private:
	TreeNode *find_right_most(TreeNode* node)
	{
		while (node!=NULL && node->right!=NULL)
		{
			node = node->right;
		}
		return node;
	}
};