class Solution 
{
public:
    TreeNode *sortedArrayToBST(vector<int> &num) 
    {
    	return gao(num, 0, num.size());
    }
private:
	TreeNode *gao(vector<int>& num, int begin, int end)
	{
		if (begin >= end)
		{
			return NULL;
		}
		TreeNode *node = new TreeNode(num[ (end-begin)/2 ]);
		node->left = gao(num, begin, (end-begin)/2-1);
		node->right = gao(num, (end-begin)/2+1, end);
		return node;
	}
};