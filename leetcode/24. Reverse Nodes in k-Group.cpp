class Solution 
{
public:
	ListNode *reverseKGroup(ListNode *head, int k) 
	{
		ListNode *cur=head, *prev, *next;

		while (cur != NULL)
		{
			int i;
			for (i=0, next=cur; i<k && next!=NULL; ++ i, next=next->next) {}
			if (i != k) 
			{ 
				break;
			}
			for (int i = k-1; i >= 1; -- i)
			{
				ListNode *node = cur, *node_prev;
				for (int j = 0; j < i; ++ j)
				{
					node_prev = node;
					node = node->next;
				}
				node->next = node_prev;
				if (i==k-1 && head==cur)
				{
					head = node;
				} else if (i==k-1)
				{
					prev->next = node;
				}
			}
			prev = cur;
			cur->next = next;
			cur = cur->next;
		}

		return head;
	}
};