class Solution 
{
public:
    ListNode *partition(ListNode *head, int x) 
    {
    	ListNode *cur = head;
    	ListNode *p_head[2] = {NULL, NULL}, *p_cur[2] = {NULL, NULL};

    	while (cur != NULL)
    	{
    		int index = (cur->val<x)? 0: 1;
    		if (p_head[index] == NULL)
    		{
    			p_head[index] = p_cur[index] = cur;
    		} else
    		{
    			p_cur[index]->next = cur;
    			p_cur[index] = cur;
    		}
			cur = cur->next;
    	}
		if (p_cur[0] != NULL)
		{
	    	p_cur[0]->next = p_head[1];
		}
		if (p_cur[1] != NULL)
		{
	    	p_cur[1]->next = NULL;
		}

		return p_head[0]!=NULL? p_head[0]: p_head[1];
    }
};