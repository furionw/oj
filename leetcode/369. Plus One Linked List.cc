// Copyright 2016 Qi Wang
// Date: 2016-12-29
class Solution {
 public:
  ListNode* plusOne(ListNode* head) {
    if (add(head) == 1) {
      auto newHead = new ListNode(1);
      newHead->next = head;
      return newHead;
    }
    return head;
  }

 private:
  int add(ListNode* node) const {
    return node->next == nullptr ? add(node, 1) : add(node, add(node->next));
  }

  int add(ListNode* node, int num) const {
    int sum = node->val + num;
    node->val = sum % 10;
    return static_cast<int>(sum == 10);
  }
};
