class Solution 
{
public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) 
    {
        in = inorder;
        post = postorder;
        return gao(0, inorder.size(), 0, postorder.size());
    }

private:
	TreeNode *gao(size_t in_begin, size_t in_end, size_t post_begin, size_t post_end)
	{	
		if (post_end==0 || in_begin==in_end)
		{
			return NULL;
		}
		TreeNode *node = new TreeNode(post[post_end-1]);
		size_t left_cnt = 0;
		for ( ; in_begin+left_cnt<in_end && in[in_begin+left_cnt]!=post[post_end-1];
			++ left_cnt) {}
		node->left = gao(in_begin, in_begin+left_cnt, post_begin, post_begin+left_cnt);
		node->right = gao(in_begin+left_cnt+1, in_end, post_begin+left_cnt, post_end-1);
		return node;
	}

	vector<int> in;
	vector<int> post;
};