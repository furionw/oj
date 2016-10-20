struct  ListNode
{
	int val;
	ListNode* next;
	ListNode(int x): val(x) {}
};

class Solution
{
public:
	ListNode* detectCycle(ListNode* head) 
	{
		ListNode* slow=head, *fast=head;
		while (fast!=NULL && fast->next!=NULL && fast->next->next!=NULL)
		{
			slow = slow->next;
			fast = fast->next->next;
			if (slow == fast)
			{
				break;
			}
		}
		if ( fast==NULL || fast->next==NULL || fast->next->next==NULL)
		{
			return NULL;
		}
		slow=head;
		while (slow != fast)
		{
			slow = slow->next;
			fast = fast->next;
		}
		return slow;
	} 
};