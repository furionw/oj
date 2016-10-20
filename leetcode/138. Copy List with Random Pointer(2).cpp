class Solution
{
public:
	RandomListNode *copyRandomList(RandomListNode *head)
	{
		if (head == NULL)
		{
			return NULL;
		}
		auto node = nodes[head->label];
		if (node == NULL)
		{
			node = new RandomListNode(head->label);
			nodes[head->label] = node;
			node->next = copyRandomList(head->next);
			node->random = copyRandomList(head->random);
		}
		return node;
	}

private:
	map<int, RandomListNode*> nodes;
};