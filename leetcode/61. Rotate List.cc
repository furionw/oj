// Copyright 2016 Qi Wang
// Date: 2016-12-15
class Solution {
 public:
  ListNode* rotateRight(ListNode* head, int k) {
    if (!head) return head;
    int len = 1;
    auto tail = head;
    for (; tail->next; tail = tail->next) ++len;
    int remainder = k % len;
    if (remainder == 0) return head;
    // update old tail’s next
    tail->next = head;
    auto newTail = head;
    // i should be assigned to 1, rather than 0
    for (int i = 1; i < len - remainder; ++i) newTail = newTail->next;
    // The head of the new list (the list after rotation)
    head = newTail->next;
    newTail->next = nullptr;
    return head;
  }
};

// Date: 2014-07
class Solution 
{
public:
    ListNode *rotateRight(ListNode *head, int k) 
    {
      if (head == NULL)
      {
        return NULL;
      }

      int size = 0;
      auto fast = head, slow = head;
      for ( ; fast != NULL; fast=fast->next, ++size) {}
      k = k % size;

      if (k == 0)
      {
        return head;
      }

      fast = head;
      for (int i = 0; i < k; fast=fast->next, ++i) {}
      for (; fast->next != NULL; slow=slow->next, fast=fast->next) {}
      fast->next = head;
      head = slow->next;
      slow->next = NULL;

      return head;
    }
};