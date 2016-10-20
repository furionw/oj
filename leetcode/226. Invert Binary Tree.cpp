#include <utility>

struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
};

class Solution
{
public:
	TreeNode* invertTree(TreeNode* root)
	{
		if (root != nullptr)
		{
			std::swap(root->left, root->right);
			invertTree(root->left);
			invertTree(root->right);
		}
		return root;
	}
};
