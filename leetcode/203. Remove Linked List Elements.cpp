class Solution 
{
public:
    ListNode* removeElements(ListNode* head, int val) 
    {
    	for ( ; head!=nullptr && head->val==val; head = head->next) {}
    	for (auto cur = head; cur!=nullptr && cur->next!=nullptr; )
    	{
    		if (cur->next->val != val)
    		{
    			cur = cur->next;
    		} else
    		{
    			auto tmp = cur->next->next;
    			cur->next = tmp;
    		}
    	}

       	return head;
    }
};