class Solution 
{
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) 
    {
    	if (node == NULL)
    	{
    		return NULL;
    	}

    	auto new_node = nodes[node->label];
    	if (new_node == NULL)
    	{
    		new_node = new UndirectedGraphNode(node->label);
    		nodes[new_node->label] = new_node;
    	}
    	for (auto it = node->neighbors.begin(); it != node->neighbors.end(); ++ it)
    	{
    		auto neighbor = nodes[(*it)->label];
    		if (neighbor == NULL)
    		{
    			neighbor = cloneGraph(*it);
    			nodes[neighbor->label] = neighbor;
    		}
    		new_node->neighbors.push_back(neighbor);
    	}
    	
    	return new_node;
    }

private:
	map<int, UndirectedGraphNode*> nodes;
};