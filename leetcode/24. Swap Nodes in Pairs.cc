// Copyright 2016 Qi Wang
// Date: 2016-12-21
class Solution {
 public:
  ListNode* swapPairs(ListNode* head) {
    if (!head || !head->next) return head;
    // initialize the "pre" pointer with the first two nodes
    auto pre = head;
    head = head->next;
    pre->next = head->next;
    head->next = pre;
    for (auto first = pre->next; first && first->next; first = pre->next) {
      pre->next = first->next;
      first->next = first->next->next;
      pre->next->next = first;
      pre = first;
    }
    return head;
  }
};

// Date: 2014-06
class Solution 
{
public:
    ListNode *swapPairs(ListNode *head) 
    {
      ListNode *cur = head, *prev;

      while(cur!=NULL && cur->next!=NULL)
      {
        if (cur == head)
        {
          auto next = cur->next->next;
          head = head->next;
          head->next = cur;
          cur->next = next;
        } else
        {
          auto next = cur->next->next;
          prev->next = cur->next;
          cur->next->next = cur;
          cur->next = next;
        }
        prev = cur;
        cur = cur->next;
      }

      return head;
    }
};
