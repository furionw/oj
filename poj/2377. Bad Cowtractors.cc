// Copyright 2017 Qi Wang
// Date: 2017-05-25
#include <queue>
#include <iostream>
#include <string>
#include <map>
#include <cassert>
#include <vector>

using namespace std;

template <class T>
struct Node {
  Node() {}
  Node(const T& t): parent(t), rank(0) {}
  int rank;
  T parent;
};

template <class T, class NodesType>
class DisjointSetBase {
 public:
  inline void unionSet(const T& key1, const T& key2) {
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
    return findSet(key1) == findSet(key2);
  }

 protected:
  NodesType nodes_;

 private:
  T findSet(const T& key) {
    Node<T>& node = nodes_[key];
    if (node.parent != key) {
      return node.parent = findSet(node.parent);
    } else {
      return node.parent;
    }
  }
};

template <class T>
class DisjointSet : public DisjointSetBase<T, map<T, Node<T> > > {
 public:
  inline void unionSet(const T& key1, const T& key2) {
    // Note that both unionSet and querySet need those two tryToMakeSet()
    tryToMakeSet(key1);
    tryToMakeSet(key2);
    DisjointSetBase<T, map<T, Node<T> > >::unionSet(key1, key2);
  }

  inline bool querySet(const T& key1, const T& key2) {
    // Note that both unionSet and querySet need those two tryToMakeSet()
    tryToMakeSet(key1);
    tryToMakeSet(key2);
    return DisjointSetBase<T, map<T, Node<T> > >::querySet(key1, key2);
  }

 private:
  inline void tryToMakeSet(const T& key) {
    // It's necessary to tell the compiler explicitly that the names are in
    // fact dependent on the instantiation of the parent, via using this->
    // Or we will get compilation error in g++
    if (this->nodes_.find(key) == this->nodes_.end())
      this->nodes_.emplace(key, key);
  }
};

template <>
class DisjointSet<size_t> : public DisjointSetBase<size_t, vector<Node<size_t> > >{
 public:
  DisjointSet(size_t sz) {
    nodes_ = vector<Node<size_t> >(sz);
    for (size_t i = 0; i < nodes_.size(); ++i) nodes_[i].parent = i;
  }
};

struct Edge {
  Edge() {}
  Edge(int u, int v, int w) : u(u), v(v), weight(w) {}

  inline bool operator <(const Edge& e) const {
    if (weight != e.weight) {
      return weight < e.weight;
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
  DisjointSet<size_t> disjoint_set(n + 1);
  for (int i = 0; i < m; ++i) {
    int a, b, c;
    cin >> a >> b >> c;
    q.push(Edge(a, b, c));
  }
  int result = 0, cnt = 0;
  while (!q.empty()) {
    Edge e = q.top(); q.pop();
    if (!disjoint_set.querySet(e.u, e.v)) {
      disjoint_set.unionSet(e.u, e.v);
      result += e.weight;
      ++cnt;
    }
  }
  cout << (n - 1 == cnt ? result : -1) << endl;
}
