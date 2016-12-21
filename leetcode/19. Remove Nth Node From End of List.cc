// Copyright 2016 Qi Wang
// Date: 2016-12-20
class Solution {
 public:
  ListNode* removeNthFromEnd(ListNode* head, int n) {
    auto pre = head, tail = head;
    for (int i = 0; i < n; ++i) tail = tail->next;
    // when n == len(head)
    if (!tail) {
      auto res = head->next;
      delete head;
      return res;
    }
    while (tail->next) {
      pre = pre->next;
      tail = tail->next;
    }
    auto toRemove = pre->next;
    pre->next = toRemove->next;
    delete toRemove;
    return head;
  }
};

// Date: 2014-06
class Solution 
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) 
    {
        ListNode* slow = head, *fast = head, *prev = NULL;
        for (int i = 0; i<n; ++ i, fast=fast->next) {}

        while (fast != NULL)
        {
            prev = slow;
            slow = slow->next;
            fast = fast->next;
        }
        
        // note that we didn't delete the n-th node here
        if (prev != NULL)
        {
            prev->next = slow->next;
        } else
        {
            head = head->next;
        }
        return head;
    }
};