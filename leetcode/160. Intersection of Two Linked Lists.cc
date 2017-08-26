// Copyright 2017 Qi Wang
// Date: 2017-08-25
class Solution {
 public:
  ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    auto get_len = [](ListNode* head) {
      int len = 0;
      for (; head != nullptr; head = head->next) ++len;
      return len;
    };
    int a_len = get_len(headA), b_len = get_len(headB);
    if (a_len < b_len) {
      swap(a_len, b_len);
      swap(headA, headB);
    }
    for (; a_len > b_len; --a_len) headA = headA->next;
    for (; headA != nullptr; headA = headA->next, headB = headB->next) {
      if (headA == headB) return headA;
    }
    return nullptr;
  }
};

class Solution 
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) 
    {
    	int a_len=0, b_len=0;
    	for (auto tmp=headA; tmp!=NULL; tmp=tmp->next, ++ a_len) {}
    	for (auto tmp=headB; tmp!=NULL; tmp=tmp->next, ++ b_len) {}
    	if (a_len > b_len)
    	{
    		for ( ; a_len>b_len; headA=headA->next, -- a_len) {} 
    	} else if (b_len > a_len)
    	{
    		for ( ; b_len>a_len; headB=headB->next, -- b_len) {}
    	}
    	while (headA != NULL)
    	{
    		if (headA == headB)
    		{
    			return headA;
    		} else 
    		{
    			headA = headA->next;
    			headB = headB->next;
    		}
    	}
    	return NULL;
    }
};