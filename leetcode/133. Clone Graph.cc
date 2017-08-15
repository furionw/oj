// Copyright 2017 Qi Wang
// Date: 2017-08-14
class Solution {
 public:
  UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
    unordered_map<UndirectedGraphNode*, UndirectedGraphNode*>
        addr_to_node_map;
    addr_to_node_map[nullptr] = nullptr;
    return CloneGraph(node, &addr_to_node_map);
  }

 private:
  UndirectedGraphNode *CloneGraph(
      UndirectedGraphNode *node,
      unordered_map<UndirectedGraphNode*, UndirectedGraphNode*>*
          addr_to_node_map) const {
    if (addr_to_node_map->find(node) != addr_to_node_map->end()) {
      return (*addr_to_node_map)[node];
    } else {
      (*addr_to_node_map)[node] = new UndirectedGraphNode(node->label);
      for (auto neighbor : node->neighbors) {
        (*addr_to_node_map)[node]->neighbors.push_back(
            CloneGraph(neighbor, addr_to_node_map)
        );
      }
      return (*addr_to_node_map)[node];
    }
  }
};

// Date: 2017-07-24
class Solution {
 public:
  UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
    if (node == nullptr) return nullptr;
    int label = node->label;
    node_map_[label] = new UndirectedGraphNode(label);
    for (auto* neighbor : node->neighbors) {
      node_map_[label]->neighbors.push_back(FindNode(neighbor));
    }
    return node_map_[label];
  }

 private:
  UndirectedGraphNode* FindNode(UndirectedGraphNode *node) {
    int label = node->label;
    return node_map_[label] = node_map_[label] != nullptr
        ? node_map_[label]
        : cloneGraph(node);
  }

  unordered_map<int, UndirectedGraphNode*> node_map_;
};

// Date: 2017-01-03
class Solution {
 public:
  UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
    if (node == nullptr) return node;
    unordered_map<int, UndirectedGraphNode*> lblToNode;
    return cloneGraph(node, lblToNode);
  }

 private:
  UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node,
      unordered_map<int, UndirectedGraphNode*>& lblToNode) const {
    auto res = lblToNode[node->label];
    if (res == nullptr) {
      res = lblToNode[node->label] = new UndirectedGraphNode(node->label);
      for (auto neighbor : node->neighbors)
        res->neighbors.push_back(cloneGraph(neighbor, lblToNode));
    }
    return res;
  }
};

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