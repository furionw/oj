// Copyright 2016 Qi Wang
// Date: 2016-10-30
class Solution {
 public:
  vector<vector<int>> pathSum(TreeNode* root, int sum) {
    vector<vector<int>> res;
    if (root) {
      if (!root->left && !root->right) {
        if (root->val == sum) res.emplace_back(1, sum);
      } else {
        pack(root->left, sum - root->val, root->val, res);
        pack(root->right, sum - root->val, root->val, res);
      }
    }
    return res;
  }

 private:
  void pack(TreeNode* node, int sum, int insert, vector<vector<int>>& res) {
    auto paths = pathSum(node, sum);
    for (auto& path : paths) {
      path.insert(path.begin(), insert);
      res.emplace_back(move(path));
    }
  }
};

// Date: 2014-08
class Solution 
{
public:
    vector<vector<int> > pathSum(TreeNode *root, int sum) 
    {
    	if (root!=NULL && root->left==NULL && root->right==NULL && root->val==sum)
    	{
    		num.push_back(root->val);
    		ret.push_back(num);
    		num.pop_back();
    	} else if (root != NULL)
    	{
    		num.push_back(root->val);
    		pathSum(root->left, sum - root->val);
    		pathSum(root->right, sum - root->val);
    		num.pop_back();
    	}
    	return ret;
    }
private:
	vector<int> num;
	vector<vector<int>> ret;
};	