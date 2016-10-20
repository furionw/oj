class Solution 
{
public:
    ListNode *deleteDuplicates(ListNode *head) 
    {
    	auto cur = head;
    	ListNode* pre_node = NULL;

    	while (cur != NULL)
    	{
	    	bool need = true;    		    		
    		auto next = cur->next;
    		while (next!=NULL && next->val==cur->val)
    		{
    			need = false;
    			next = next->next;
    		}
    		if (need)
    		{
    			pre_node = cur;
    			cur = next;
    		} else if(pre_node == NULL)
    		{
    			head = next;
    			cur = next;
    		} else 
    		{
    			pre_node->next = next;
    			cur = next;
    		}
    	}

    	return head;
    }
};