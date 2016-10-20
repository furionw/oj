#include <vector>
#include <stack>

using namespace std;

struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
	vector<int> preorderTraversal(TreeNode *root) 
	{
		vector<int> ret;
		stack<TreeNode*> node_stack;

		node_stack.push(root);
		while (node_stack.empty()==false)
		{
			TreeNode* top = node_stack.top();
			node_stack.pop();
			if (top == NULL)
			{
				continue;
			}
			ret.push_back(top->val);
			node_stack.push(top->right);
			node_stack.push(top->left);
		}

		return ret;
    }
};