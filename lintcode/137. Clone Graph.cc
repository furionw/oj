// Copyright 2017 Qi Wang
// Date: 2017-10-21
class Solution {
 public:
  UndirectedGraphNode* cloneGraph(UndirectedGraphNode* node) {
    unordered_map<int, UndirectedGraphNode*> label_to_node_map;
    return CloneGraph(&label_to_node_map, node);
  }
 
 private:
  UndirectedGraphNode* CloneGraph(
      unordered_map<int, UndirectedGraphNode*>* label_to_node_map,
      UndirectedGraphNode* node) const {
    if (node == nullptr) return nullptr;
    if (label_to_node_map->count(node->label)) {
      return (*label_to_node_map)[node->label];
    } else {
      auto* ptr = (*label_to_node_map)[node->label] =
                  new UndirectedGraphNode(node->label);
      for (auto* neighbor : node->neighbors) {
        ptr->neighbors.push_back(CloneGraph(label_to_node_map, neighbor));
      }
      return ptr;
    }
  }
};
