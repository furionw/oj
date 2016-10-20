class Solution 
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) 
    {
    	ListNode* slow = head, *fast = head;
    	for (int i = 0; i < n; ++ i, fast = fast->next) {}

    	while (fast != NULL)
		{
			slow = slow->next;
			fast = fast->next;
		}
		slow->next = slow->next->next;
		// note that we didn't delete node here

    	return head;
    }
};