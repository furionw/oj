// Copyright 2016 Qi Wang
// Date: 2016-10-19
#include <queue>
#include <iostream>
#include <string>
#include <unordered_map>
#include <cassert>

using std::cin; using std::cout; using std::endl;
using std::priority_queue;
using std::unordered_map;

template <class T>
struct Node {
  Node() {}
  Node(const T& t): parent(t) {}
  int rank = 0;
  T parent;
};

template <class T>
class DisjointSet {
 public:
  inline void unionSet(const T& key1, const T& key2) {
    // Note that both unionSet and querySet need those two tryToMakeSet()
    tryToMakeSet(key1);
    tryToMakeSet(key2);
    T s1 = findSet(key1), s2 = findSet(key2);
    if (s1 != s2) {
      Node<T>& node1 = nodes_[s1], node2 = nodes_[s2];
      if (node1.rank > node2.rank) {
        node2.parent = node1.parent;
      } else {
        node1.parent = node2.parent;
        if (node1.rank == node2.rank) ++node2.rank;
      }
    }
  }

  inline bool querySet(const T& key1, const T& key2) {
    // Note that both unionSet and querySet need those two tryToMakeSet()
    tryToMakeSet(key1);
    tryToMakeSet(key2);
    return findSet(key1) == findSet(key2);
  }

 private:
  T findSet(const T& key) {
    Node<T>& node = nodes_[key];
    if (node.parent != key) {
      return node.parent = findSet(node.parent);
    } else {
      return node.parent;
    }
  }

  inline void tryToMakeSet(const T& key) {
    if (nodes_.find(key) == nodes_.end()) nodes_.emplace(key, key);
  }
  unordered_map<T, Node<T>> nodes_;
};

struct Edge {
  Edge() {}
  Edge(int u, int v, int w) : u(u), v(v), weight(w) {}

  inline bool operator <(const Edge& e) const {
    if (weight != e.weight) {
      return weight > e.weight;
    } else {
      if (u != e.u) return u > e.u;
      if (v != e.v) return v > e.v;
      // Order must be resolved between different edges
      assert(false);
    }
  }

  int u, v, weight;
};

int main() {
  priority_queue<Edge> q;
  int n, m;
  cin >> n >> m;
  while (m--) {
    int u, v, w;
    cin >> u >> v >> w;
    q.emplace(u, v, w);
  }
  DisjointSet<int> forest;
  int res = 0;
  while (!q.empty()) {
    auto& edge = q.top();
    if (!forest.querySet(edge.u, edge.v)) {
      res += edge.weight;
      forest.unionSet(edge.u, edge.v);      
    }
    q.pop();
  }
  cout << res << endl;
}
