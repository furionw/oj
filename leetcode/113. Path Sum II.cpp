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