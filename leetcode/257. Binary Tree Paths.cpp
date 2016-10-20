#include <sstream>
#include <string>
#include <iostream>
#include <vector>

using namespace std;

  // struct TreeNode {
  //     int val;
  //     TreeNode *left;
  //     TreeNode *right;
  //     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  // };
 


class Solution 
{
public:
    vector<string> binaryTreePaths(TreeNode* root) 
    {
    	string path;
    	dfs(path, root);
    	return ret;
    }

private:
	void dfs(string& pre_path, TreeNode* cur)
	{
		if (cur == nullptr)
		{
			return ;
		} else if (cur->left==nullptr && cur->right==nullptr)
		{
			ret.push_back(pre_path + int_to_string(cur->val));
		} else 
		{
			string cur_path = pre_path + int_to_string(cur->val) + "->";
			dfs(cur_path, cur->left);
			dfs(cur_path, cur->right);
		}
	}

	string int_to_string(int num)
	{
		stringstream ss;
		ss << num;
		return ss.str();
	}

	vector<string> ret;
};