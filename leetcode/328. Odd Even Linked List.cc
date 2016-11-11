// Copyright 2016 Qi Wang
// Date: 2016-11-11
class Solution {
 public:
  ListNode* oddEvenList(ListNode* head) {
    if (!head) return head;
    auto evenHead = head->next;
    auto oddTail = head, evenTail = evenHead;
    while (evenTail && evenTail->next) {
      oddTail = oddTail->next = evenTail->next;
      if (oddTail)
        evenTail = evenTail->next = oddTail->next;
    }
    oddTail->next = evenHead;
    if (evenTail) evenTail->next = nullptr;
    return head;
  }
};
