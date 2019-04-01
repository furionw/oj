// Copyright 2017 Qi Wang
// Date: 2017-10-13
// Refer to: https://discuss.leetcode.com/topic/104729/10-line-java-solution-union-find
class Solution {
 public:
  vector<int> findRedundantConnection(vector<vector<int>>& edges) {
    vector<int> parent(edges.size() + 1);
    for (int i = 1; i < parent.size(); ++i) {
      parent[i] = i;
    }
    for (const auto& edge : edges) {
      int i = UnionFind(&parent, edge[0]);
      int j = UnionFind(&parent, edge[1]);
      if (i == j) {
        return {edge[0], edge[1]};
      } else {
        parent[j] = i;
      }
    }
    return {0, 0};  // comfort the compiler
  }
 
 private:
  int UnionFind(vector<int>* parent, int x) const {
    return (*parent)[x] == x ? x
                             : (*parent)[x] = UnionFind(parent, (*parent)[x]);
  }
};
