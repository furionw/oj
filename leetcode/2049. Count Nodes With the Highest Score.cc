// 2025-06-19
struct Node {
  Node *parent = nullptr;
  vector<Node*> children;
  int size = 1;
};

class Solution {
 public:
  int countHighestScoreNodes(vector<int>& parents) {
    int n = parents.size();
    vector<Node> nodes(n, Node {});
    for (int i = 1; i < n; ++i) {
      int p = parents[i];
      nodes[i].parent = &nodes[p];
      nodes[p].children.push_back(&nodes[i]);
    }
    size(&nodes[0]);
    int count = 0;
    long long score = 0;
    for (int i = 0; i < n; ++i) {
      long long num = max(1, n - nodes[i].size);
      for (auto child : nodes[i].children) {
        num *= child->size;
      }
      if (num > score) {
        count = 1;
        score = num;
      } else if (num == score) {
        ++count;
      }
    }
    return count;
  }

 private:
  int size(Node* node) {
    for (auto child : node->children) {
      node->size += size(child);
    }
    return node->size;
  }
};
