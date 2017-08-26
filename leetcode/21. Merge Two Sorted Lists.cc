// Copyright 2017 Qi Wang
// Date: 2017-08-25
class Solution {
 public:
  ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    ListNode dummy(0);
    ListNode* cur = &dummy;
    while (l1 != nullptr && l2 != nullptr) {
      if (l1->val < l2->val) {
        cur->next = l1;
        l1 = l1->next;
      } else {
        cur->next = l2;
        l2 = l2->next;
      }
      cur = cur->next;
    }
    cur->next = l1 != nullptr ? l1 : l2;
    return dummy.next;
  }
};

// Date: 2016-12-21
class Solution {
 public:
  ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    ListNode dummy(-1);
    auto head = &dummy;
    for (; l1 && l2; head = head->next) {
      if (l1->val < l2->val) {
        head->next = l1;
        l1 = l1->next;
      } else {
        head->next = l2;
        l2 = l2->next;
      }
    }
    head->next = l1 ? l1 : l2;
    return dummy.next;
  }
};

// Date: 2014-07
class Solution 
{
public:
  ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) 
  {
    ListNode* head=NULL, **p=&head;

    while (l1!=NULL && l2!=NULL)
    {
      if(l1->val < l2->val)
      {
        *p = l1;
        l1 = l1->next;
      } else
      {
        *p = l2;
        l2 = l2->next;
      }
      p = &((*p)->next);
    }
    *p = l1!=NULL? l1: l2;
    
    return head;
  }
};
