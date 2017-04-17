// Copyright 2017 Qi Wang
// Date: 2017-04-17
class Solution {
 public:
  ListNode* FindKthToTail(ListNode* head, int k) {
    if (head == nullptr) return nullptr;
    auto tail = head;
    while (tail != nullptr && k-- > 0) tail = tail->next;
    // invalid input: list.size() < k
    if (k > 0) return nullptr;
    while (tail != nullptr) {
      head = head->next;
      tail = tail->next;
    }
    return head;
  }
};
