class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2, int carry = 0) {
        if (l1 != nullptr && l2 != nullptr) {
            int sum = l1->val + l2->val + carry;
            auto res = new ListNode(sum % 10);
            res->next = addTwoNumbers(l1->next, l2->next, sum / 10);
            return res;
        } else 
            return l1 != nullptr? 
                addSingleNumber(l1, carry): addSingleNumber(l2, carry);
    }

private:
    ListNode* addSingleNumber(ListNode* node, int carry) {
        if (node != nullptr) {
            int sum = node->val + carry;
            auto res = new ListNode(sum % 10);
            res->next = addSingleNumber(node->next, sum / 10);
            return res;
        } else 
            return carry==1? new ListNode(1): nullptr;
    }
};

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