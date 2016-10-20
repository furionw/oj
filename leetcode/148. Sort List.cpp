#include <iostream>

using namespace std;

struct  ListNode
{
	int val;
	ListNode* next;
	ListNode(int x): val(x) {}
};

class Solution
{
public:
	ListNode* sortList(ListNode* head)
	{
		if (head == NULL || head->next==NULL)
		{
			return head;
		}

		ListNode* fast=head, *slow=head;
		for ( ; fast->next!=NULL&&fast->next->next!=NULL; fast=fast->next->next, slow=slow->next) {}
		fast = slow;
		slow = slow->next;
		fast->next = NULL;
		fast = sortList(head); // half before 
		slow = sortList(slow); // half after

		return merge(fast, slow);
	}

	ListNode* merge(ListNode* before, ListNode* after)
	{
		ListNode* head;
		if ( before->val < after->val )
		{
			head = before;
			before = before->next;
		} else
		{
			head = after;
			after = after->next;
		}

		ListNode* now = head;
		while ( before!=NULL && after!=NULL )
		{
			if (before->val < after->val)
			{
				now->next = before;
				before = before->next;
			} else
			{
				now->next = after;
				after = after->next;
			}
			now = now->next;			
		}
		if (before != NULL) { now->next = before; }
		if (after  != NULL) { now->next = after; }
		return head;
	}
};