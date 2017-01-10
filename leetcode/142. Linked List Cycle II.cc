// Copyright 2017 Qi Wang

// Date: 2017-01-04
// Refer to: https://discuss.leetcode.com/topic/5284/concise-o-n-solution-by-using-c-with-detailed-alogrithm-description
// The above link has provided the solid proof.

// Date: ...
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
