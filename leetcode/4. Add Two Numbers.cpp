// struct ListNode {
// 	int val;
// 	ListNode* next;
// 	ListNode(int x): val(x), next(NULL) {}
// };

// first time
class Solution
{
public:
	ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) 
	{
    	ListNode* head = NULL, *current=NULL;
    	int carry = 0;

    	for ( ; l1!=NULL && l2!=NULL; l1 = l1->next, l2=l2->next)
    	{
    		if (head==NULL)
    		{
    			head = current = new ListNode((l1->val+l2->val+carry)%10);
    			carry = (l1->val+l2->val+carry) / 10;
    		} else
    		{
    			current->next = new ListNode((l1->val+l2->val+carry)%10);
    			carry = (l1->val+l2->val+carry) / 10;
    			current = current->next;
    		}
    	}
    	for ( ; l1!=NULL; l1 = l1->next)
    	{
    		current->next = new ListNode((l1->val+carry)%10);
    		carry = (l1->val+carry)/10;
    		current = current->next;
    	}
    	for ( ; l2!=NULL; l2 = l2->next)
    	{
    		current->next = new ListNode((l2->val+carry)%10);
    		carry = (l2->val+carry)/10;
    		current = current->next;
    	}
    	if (carry == 1)
    	{
    		current->next = new ListNode(1);
    	}

    	return head;
    }
};