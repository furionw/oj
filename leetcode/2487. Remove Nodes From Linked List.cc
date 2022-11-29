// Date: 2022-11-26
class Solution {
 public:
  ListNode* removeNodes(ListNode* head) {
    stack<ListNode*> s;
    for (; head != nullptr; head = head->next) {
      s.push(head);
    }
    int rightMax = 0;
    ListNode* prev = nullptr;
    for (; !s.empty(); s.pop()) {
      auto node = s.top();
      if (node->val < rightMax) {
        continue;
      }
      // val >= rightMax
      rightMax = node->val;
      node->next = prev;
      prev = node;
    }
    return prev;
  }
};
