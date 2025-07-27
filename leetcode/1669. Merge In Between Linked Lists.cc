// 2025-07-26
class Solution {
 public:
  ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
    ListNode *aPrev = nullptr, *bNext = nullptr;
    int cnt = 0;
    for (ListNode *node = list1, *prev = nullptr; node != nullptr; node = node->next) {
      if (cnt == a) {
        aPrev = prev;
      }
      if (cnt == b) {
        bNext = node->next;
      }
      prev = node;
      ++cnt;
    }

    // bNext can be null
    // a and b may point to the same node
    aPrev->next = list2;
    for (; list2->next != nullptr; list2 = list2->next) {}
    list2->next = bNext;

    return list1;
  }
};
