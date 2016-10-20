// Copyright 2016 Stephen Wong
// Date: 2016-10-01
class Solution {
 public:
  void deleteNode(ListNode* node) {
    *node = *(node->next);
  }
};
