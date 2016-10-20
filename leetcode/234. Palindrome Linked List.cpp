// Copyright 2016 Stephen Wong
// Date: 2016-09-30
class Solution {
 public:
  bool isPalindrome(ListNode* head) {
    if (head == nullptr) return true;
    int length = 0;
    for (auto node = head; node != nullptr; node = node->next)
      ++length;
    int offset = (length - 1) >> 1;
    ListNode* pre;
    for (pre = head; offset--; pre = pre->next) {}
    auto secondHead = reverse(pre->next);
    for (; secondHead != nullptr;
        secondHead = secondHead->next, head = head->next)
      if (head->val != secondHead->val)
        return false;
    return true;
  }

 private:
  inline ListNode* reverse(ListNode* node) const {
    ListNode* pre = nullptr;
    while (node != nullptr) {
      auto next = node->next;
      node->next = pre;
      pre = node;
      node = next;
    }
    return pre;
  }
};
