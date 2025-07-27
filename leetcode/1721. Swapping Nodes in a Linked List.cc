// 2025-07-26
class Solution {
 public:
  ListNode* swapNodes(ListNode* head, int k) {
    int n = 0;
    ListNode* node1;
    for (auto node = head; node != nullptr; node = node->next) {
      if (++n == k) {
        node1 = node;
      }
    }
    ListNode* node2 = nullptr;
    if (2 * k - 1 == n) {
      return head;
    // k = 4, n = 8
    // 4 < 5
    // 9 - 4 - 4 = 1
    // k = 2, n = 7
    } else if (k < (n + 1) - k) {
      int steps = (n + 1) - k - k;
      for (node2 = node1; steps > 0; --steps) {
        node2 = node2->next;
      }
    } else {
      int steps = n - k;
      for (node2 = head; steps > 0; --steps) {
        node2 = node2->next;
      }
    }
    swap(node1->val, node2->val);
    return head;
  }
};
