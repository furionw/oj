#include <iostream>

using namespace std;

struct ListNode
{
	int val;
	ListNode* next;
	ListNode(int x): val(x), next(NULL) {}
	void insert(int x)
	{
		if (next == NULL)
		{
			next = new ListNode(x);
		} else
		{
			ListNode* tmp = next;
			for ( ; tmp->next!=NULL; tmp=tmp->next) {}
			tmp->next = new ListNode(x);
		}		
	}
};

class Solution 
{
public:
    void reorderList(ListNode *head) 
    {
    	if (head == NULL || head->next==NULL)
    	{
    		return ;
    	}

    	// slow, towards, # = ceiling(n/2.0)
        ListNode *fast= head, *slow=head;
        for( ; fast->next!=NULL && fast->next->next!=NULL; slow = slow->next, fast = fast->next->next ) {}
        fast = slow->next;
        slow->next = NULL;
        slow = head;
        // fast, backwards, # = floor(n/2.0)
		ListNode* prev = fast;
		fast = fast->next;
		prev->next = NULL;
        while (fast != NULL)
        {
        	ListNode* tmp = fast->next;
        	fast->next = prev;
        	prev = fast;
        	fast = tmp;
        }
        fast = prev;

        for (ListNode* slow_next, *fast_next; fast != NULL; slow=slow_next, fast=fast_next)
        {
			slow_next = slow->next;
			fast_next = fast->next;
        	slow->next = fast;
        	fast->next = slow_next;
        }
    }
};

int main()
{
	ListNode test(1);
	test.insert(2);
	test.insert(3);
	test.insert(4);

	Solution a;
	a.reorderList(&test);

	cout << 1;
	return 0;
}