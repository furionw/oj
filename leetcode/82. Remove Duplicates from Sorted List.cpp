class Solution 
{
public:
    ListNode *deleteDuplicates(ListNode *head) 
    {
   		auto cur = head;     

   		while (cur != NULL)
   		{
   			auto next = cur->next;
   			while (next!=NULL && next->val == cur->val)
   			{
   				cur->next = next->next;
   				free(next);
   				next = cur->next;
   			}
   			cur = next;
   		}

   		return head;
    }
};