class Solution 
{
public:
    int maxPathSum(TreeNode *root) 
    {
        m_ret = INT_MIN;

        int val = root->val;
        if (root->left != NULL)
        {
            int left = single_side(root->left);
            val += (left>0? left: 0);
        }
        if (root->right != NULL)
        {
            int right = single_side(root->right);
            val += (right>0? right: 0);
        }

        return max(val, m_ret);
    }   
private:
    int m_ret;

    int single_side(TreeNode *node)
    {
        int val = node->val;

        if (node->left!=NULL && node->right!=NULL)
        {
            int left = single_side(node->left);
            int right = single_side(node->right);
            m_ret = max(m_ret, val+left+right);
            int larger = max(left, right);
            val += (larger>0? larger: 0);
        } else if (node->left != NULL)
        {
            int left = single_side(node->left);
            val += (left>0? left: 0);            
        } else if (node->right != NULL)
        {
            int right = single_side(node->right);
            val += (right>0? right: 0);
        }
        m_ret = max(m_ret, val);

        return val;
    }
};