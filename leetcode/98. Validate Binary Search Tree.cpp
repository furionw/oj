class Solution {
 public:
  bool isValidBST(TreeNode* root) {
    if (nullptr != root) {
      if (nullptr != root->left &&
      	  (!isValidBST(root->left) || gao(root->left).second >= root->val))
      	return false;
      if (nullptr != root->right &&
      	  (!isValidBST(root->right) || gao(root->right).first <= root->val))
      	return false;
    }
    return true;
  }
  
 private:
 	pair<int, int> gao(TreeNode* node) {
    assert(nullptr != node);
    return make_pair(
    	nullptr != node->left? gao(node->left).first: node->val,
    	nullptr != node->right? gao(node->right).second: node->val);
 	}
};

// Error: cannot handle the case [-2147483648,null,2147483647]
class Solution 
{
public:
    bool isValidBST(TreeNode *root) 
    {
    	return gao(root, INT_MIN, INT_MAX);
    }

private:
	bool gao(TreeNode *node, int lower_bound, int upper_bound)
	{
		if (node==NULL || (node->left==NULL && node->right==NULL))
		{
			return true;
		} else if (node->left!=NULL && node->right!=NULL)
		{
			return node->left->val < node->val
				&& node->left->val > lower_bound
				&& node->right->val > node->val
				&& node->right->val < upper_bound
				&& gao(node->left, lower_bound, node->val)
				&& gao(node->right, node->val, upper_bound);
		} else if (node->left==NULL && node->right!=NULL)
		{
			return node->right->val > node->val
				&& node->right->val < upper_bound
				&& gao(node->right, node->val, upper_bound);
		} else if (node->left!=NULL && node->right==NULL)
		{
			return node->left->val < node->val
				&& node->left->val > lower_bound
				&& gao(node->left, lower_bound, node->val);
		}
		return false;
	}
};