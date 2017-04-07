// Copyright 2017 Qi Wang
// Date: 2017-04-07
class Solution {
 public:
  ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
    int len1 = 0, len2 = 0;
    for (auto temp = pHead1; temp != nullptr; temp = temp->next) ++len1;
    for (auto temp = pHead2; temp != nullptr; temp = temp->next) ++len2;
    if (len1 > len2) {
      for (; len1 > len2; pHead1 = pHead1->next) --len1;
    } else {
      for (; len2 > len1; pHead2 = pHead2->next) --len2;
    }
    while (pHead1 != nullptr) {
      if (pHead1 == pHead2) {
        return pHead1;
      } else {
        pHead1 = pHead1->next;
        pHead2 = pHead2->next;
      }
    }
    return nullptr;
  }
};
