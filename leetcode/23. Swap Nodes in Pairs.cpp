class Solution 
{
public:
    ListNode *swapPairs(ListNode *head) 
    {
    	ListNode *cur = head, *prev;

    	while(cur!=NULL && cur->next!=NULL)
    	{
    		if (cur == head)
    		{
    			auto next = cur->next->next;
    			head = head->next;
    			head->next = cur;
    			cur->next = next;
    		} else
    		{
    			auto next = cur->next->next;
    			prev->next = cur->next;
    			cur->next->next = cur;
    			cur->next = next;
    		}
    		prev = cur;
    		cur = cur->next;
    	}

    	return head;
    }
};