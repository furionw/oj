class Solution 
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) 
    {
    	int a_len=0, b_len=0;
    	for (auto tmp=headA; tmp!=NULL; tmp=tmp->next, ++ a_len) {}
    	for (auto tmp=headB; tmp!=NULL; tmp=tmp->next, ++ b_len) {}
    	if (a_len > b_len)
    	{
    		for ( ; a_len>b_len; headA=headA->next, -- a_len) {} 
    	} else if (b_len > a_len)
    	{
    		for ( ; b_len>a_len; headB=headB->next, -- b_len) {}
    	}
    	while (headA != NULL)
    	{
    		if (headA == headB)
    		{
    			return headA;
    		} else 
    		{
    			headA = headA->next;
    			headB = headB->next;
    		}
    	}
    	return NULL;
    }
};