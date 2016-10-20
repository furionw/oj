class Solution 
{
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) 
    {
    	pre = preorder;
    	in = inorder;
    	return gao(0, preorder.size(), 0, inorder.size());
   	}
private:
	TreeNode *gao(size_t pre_begin, size_t pre_end, size_t in_begin, size_t in_end)
	{
		if (pre_begin>=pre.size() || pre_begin==pre_end)
		{
			return NULL;
		}
		auto node = new TreeNode(pre[pre_begin]);
		size_t left_cnt = 0;
		for ( ; in_begin+left_cnt<in_end && in[in_begin+left_cnt]!=pre[pre_begin];
			++ left_cnt) {}
		node->left = gao(pre_begin+1, pre_begin+1+left_cnt, in_begin, in_begin+left_cnt);
		node->right = gao(pre_begin+1+left_cnt, pre_end, in_begin+left_cnt+1, in_end);
		return node;
	}
	vector<int> pre;
	vector<int> in;
};
