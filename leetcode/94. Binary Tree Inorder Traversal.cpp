class Solution 
{
public:
    vector<int> inorderTraversal(TreeNode *root) 
    {
    	vector<int> ret;
    	gao(root, ret);
    	return ret;
    }
private:
	void gao(TreeNode* node, vector<int>& ret)
	{
		if (node != NULL)
		{
			gao(node->left, ret);
			ret.push_back(node->val);
			gao(node->right, ret);
		}
	}
};