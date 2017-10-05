// Copyright 2017 Qi Wang
// Date: 2017-10-05
// Method 2
class Solution {
 public:
  ListNode * reverse(ListNode * head) {
    ListNode* prev = nullptr;
    while (head != nullptr) {
      swap(prev, head->next);
      swap(prev, head);
    }
    return prev;
  }
};
 
// Date: 2017-10-05
// Method 1
class Solution {
 public:
  ListNode * reverse(ListNode * head) {
    ListNode* prev = nullptr;
    while (head != nullptr) {
      auto next = head->next;
      head->next = prev;
      prev = head;
      head = next;
    }
    return prev;
  }
};
