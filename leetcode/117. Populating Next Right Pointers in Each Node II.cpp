class Solution 
{
public:
    void connect(TreeLinkNode *root) 
    {
    	queue<TreeLinkNode*> nodes;
    	queue<TreeLinkNode*> children;
    	nodes.push(root);
    	nodes.push(NULL);
    	while ( nodes.front() != NULL )
    	{
	    	auto cur = nodes.front();
	    	nodes.pop();
	    	cur->next = nodes.front();
	    	if (cur->left != NULL)
	   		{
	   			children.push( cur->left );
	   		}
	   		if (cur->right != NULL)
    		{
       			children.push( cur->right );
	   		}
	   		if (nodes.front() == NULL)
	   		{
    			nodes = children;
    			nodes.push(NULL);
    			while (children.empty() == false)
    			{
    				children.pop();
    			}
    		}
    	}
    }
};