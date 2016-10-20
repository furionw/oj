/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator 
{
public:
    BSTIterator(TreeNode *root) 
    {
        for ( ; root != nullptr; root = root->left)
        {
            stk.push(root);
        }
    }

    /** @return whether we have a next smallest number */
    bool hasNext() 
    {
        return !stk.empty();
    }

    /** @return the next smallest number */
    int next() 
    {
        auto node = stk.top();
        int val = node->val;
        stk.pop();
        node = node->right;
        for ( ; node != nullptr; node = node->left)
        {
            stk.push(node);
        }
        return val;
    }

private:
    stack<TreeNode*> stk;
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */