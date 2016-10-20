class Solution 
{
public:
    ListNode *rotateRight(ListNode *head, int k) 
    {
    	if (head == NULL)
    	{
    		return NULL;
    	}

    	int size = 0;
    	auto fast = head, slow = head;
    	for ( ; fast != NULL; fast=fast->next, ++size) {}
    	k = k % size;

    	if (k == 0)
    	{
    		return head;
    	}

    	fast = head;
    	for (int i = 0; i < k; fast=fast->next, ++i) {}
    	for (; fast->next != NULL; slow=slow->next, fast=fast->next) {}
    	fast->next = head;
    	head = slow->next;
    	slow->next = NULL;

    	return head;
    }
};