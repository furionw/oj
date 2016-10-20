class Solution 
{
public:
    vector<int> rightSideView(TreeNode *root) 
    {
        bfs(root, 1);
        return ret;
    }
private:
	void bfs(TreeNode* node, int level)
	{
		if (node == nullptr)
		{
			return ;
		}
		if (ret.size() < level)
		{
			ret.push_back(node->val);
		}
		bfs(node->right, level+1);
		bfs(node->left, level+1);
	}
	vector<int> ret;
};