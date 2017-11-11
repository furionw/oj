// Copyright 2017 Qi Wang
// Date: 2017-11-10
class Solution {
 public:
  bool isPalindrome(ListNode* head) {
    if (head == nullptr) return true;
    int len = 0;
    for (auto cur = head; cur != nullptr; cur = cur->next) {
      ++len;
    }
    int offset = (len + 1) >> 1;
    auto head2 = head;
    for (int i = 0; i < offset; ++i) {
      head2 = head2->next;
    }
    head2 = Reverse(head2);
    for (; head != nullptr && head2 != nullptr;
         head = head->next, head2 = head2->next) {
      if (head->val != head2->val) {
        return false;
      }
    }
    return true;
  }
 
 private:
  ListNode* Reverse(ListNode* head) const {
    ListNode* prev = nullptr;
    while (head != nullptr) {
      swap(prev, head->next);
      swap(prev, head);
    }
    return prev;
  }
};

// Date: 2017-08-03
class Solution {
 public:
  bool isPalindrome(ListNode* head) {
    if (head == nullptr) return true;
    int len = 0;
    for (auto cur = head; cur != nullptr; cur = cur->next, ++len) {}
    int cnt = 0;
    ListNode* prev = nullptr;
    for (ListNode* cur = head; cur != nullptr;) {
      if (++cnt > len / 2) {
        auto next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
      } else {
        cur = cur->next;
      }
    }
    for (auto head2 = prev; head != nullptr && head2 != nullptr;
        head = head->next, head2 = head2->next)
      if (head->val != head2->val) return false;
    return true;
  }
};

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
