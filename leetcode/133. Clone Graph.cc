// Copyright 2016 Qi Wang
// Date: 2016-12-16
class Solution {
 public:
  UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
    if (!node) return node;
    auto res = lblToNode_[node->label];
    if (!res) {
      res = lblToNode_[node->label] = new UndirectedGraphNode(node->label);
      for (auto neighbor : node->neighbors)
        res->neighbors.push_back(cloneGraph(neighbor));
    }
    return res;
  }

 private:
  unordered_map<int, UndirectedGraphNode*> lblToNode_;
};

// Date: 2015-02
class Solution 
{
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) 
    {
      if (node == NULL)
      {
        return NULL;
      }

      auto new_node = nodes[node->label];
      if (new_node == NULL)
      {
        new_node = new UndirectedGraphNode(node->label);
        nodes[new_node->label] = new_node;
      }
      for (auto it = node->neighbors.begin(); it != node->neighbors.end(); ++ it)
      {
        auto neighbor = nodes[(*it)->label];
        if (neighbor == NULL)
        {
          neighbor = cloneGraph(*it);
          nodes[neighbor->label] = neighbor;
        }
        new_node->neighbors.push_back(neighbor);
      }
      
      return new_node;
    }

private:
  map<int, UndirectedGraphNode*> nodes;
};