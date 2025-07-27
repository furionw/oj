// 2025-07-26
class Solution {
 public:
  ListNode* middleNode(ListNode* head) {
    auto fast = head;
    while (fast->next != nullptr) {
      head = head->next;
      fast = fast->next;
      if (fast->next != nullptr) {
        fast = fast->next;
      }
    }
    return head;
  }
};
