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
	vector<int> postorderTraversal(TreeNode* root)
	{
		vector<int> ret;
		stack<pair<TreeNode*, bool>>  node_stack;

		if (root == NULL)
		{
			return ret;
		}

		node_stack.push(make_pair(root, false));
		while (node_stack.empty() == false )
		{
			auto top = node_stack.top();
			if (top.second == true)
			{
				ret.push_back(top.first->val);
				node_stack.pop();				
				continue;
			} else
			{
				node_stack.top().second = true; // cannot use top.second=true here!
			}

			bool child = true;
			if (top.first->right != NULL) // right first 
			{
				node_stack.push(make_pair(top.first->right, false));
				child = false;
			}
			if (top.first->left != NULL)
			{
				node_stack.push(make_pair(top.first->left, false));
				child = false;
			}
			if (child == true)
			{
				ret.push_back(top.first->val);
				node_stack.pop();
			}
		}

		return ret;
	}		
};

class Solution
{
public:
	vector<int> postorderTraversal(TreeNode* root)
	{
		vector<int> ret;
		postorderTraversal_inner(root, ret);
		return ret;
	}	
private:
	void postorderTraversal_inner(TreeNode* root, vector<int>& vt_out)
	{
		if (root == NULL)
		{
			return ;
		}
		postorderTraversal_inner(root->left, vt_out);
		postorderTraversal_inner(root->right, vt_out);
		vt_out.push_back(root->val);
	}
};