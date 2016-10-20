class Solution 
{
public:
    ListNode *reverseBetween(ListNode *head, int m, int n) 
    {
    	if (head==NULL || m==n)
    	{
    		return head;
    	}

    	ListNode *cut=head, *cur=head;

    	for (int i = 1; i < m; ++ i)
    	{
    		cut = cur;
    		cur = cur->next;
    	}
    	ListNode* prev = cur;
    	cur = cur->next;
    	for (int i = 0; i < n-m; ++ i)
    	{
    		ListNode* next = cur->next;
    		cur->next = prev;
    		prev = cur;
    		cur = next;
    	}

    	if (m == 1)
    	{
    		head->next = cur;
    		return prev;    		
    	} else
    	{
	    	cut->next->next = cur;
    		cut->next = prev;
    		return head;
    	}
    }
};