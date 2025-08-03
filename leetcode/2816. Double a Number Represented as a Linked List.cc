// 2025-07-29
class Solution {
 public:
  ListNode* doubleIt(ListNode* head) {
    stack<ListNode*> s;
    int carry = 0;
    for (auto node = head; node != nullptr; node = node->next) {
      s.push(node);
    }
    while (!s.empty()) {
      auto node = s.top();
      s.pop();
      node->val *= 2;
      node->val += carry;
      carry = node->val >= 10 ? 1 : 0;
      node->val %= 10;
    }
    return carry == 0 ? head : new ListNode(1, head);
  }
};
