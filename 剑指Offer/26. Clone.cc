// Copyright 2017 Qi Wang
// Date: 2017-04-10
class Solution {
 public:
  RandomListNode* Clone(RandomListNode* pHead) {
    unordered_map<int, RandomListNode*> nodes;
    return Clone(pHead, nodes);
  }

 private:
  RandomListNode* Clone(RandomListNode* node,
      unordered_map<int, RandomListNode*>& nodes) const {
    if (node == nullptr) return nullptr;
    // exist
    if (nodes.count(node->label)) return nodes[node->label];
    // non-exist
    auto new_node = new RandomListNode(node->label);
    nodes[node->label] = new_node;
    new_node->next = Clone(node->next, nodes);
    new_node->random = Clone(node->random, nodes);
    return new_node;
  }
};
