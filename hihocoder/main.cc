// Copyright 2016 Qi Wang
// Date: 2016-10-19
#include <unordered_map>
#include <vector>
#include <iostream>
#include <string>

using std::cin; using std::cout; using std::endl;
using std::unordered_map;
using std::vector;
using std::string;

template <class T>
struct Node {
  Node() {}
  Node(const T& t): parent(t) {}
  int rank = 0;
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
class DisjointSet : public DisjointSetBase<T, unordered_map<T, Node<T>>> {
 public:
  inline void unionSet(const T& key1, const T& key2) {
    // Note that both unionSet and querySet need those two tryToMakeSet()
    tryToMakeSet(key1);
    tryToMakeSet(key2);
    DisjointSetBase<T, unordered_map<T, Node<T>>>::unionSet(key1, key2);
  }

  inline bool querySet(const T& key1, const T& key2) {
    // Note that both unionSet and querySet need those two tryToMakeSet()
    tryToMakeSet(key1);
    tryToMakeSet(key2);
    return DisjointSetBase<T, unordered_map<T, Node<T>>>::querySet(key1, key2);
  }

 private:
  inline void tryToMakeSet(const T& key) {
    if (nodes_.find(key) == nodes_.end()) nodes_.emplace(key, key);
  }
};

template <>
class DisjointSet<size_t> : public DisjointSetBase<size_t, vector<Node<size_t>>>{
 public:
  DisjointSet(size_t sz) {
    nodes_ = vector<Node<size_t>>(sz);
    for (size_t i = 0; i < nodes_.size(); ++i) nodes_[i].parent = i;
  }
};

int main() {
  DisjointSet<string> s;
  int n;
  cin >> n;
  while (n--) {
    int type;
    cin >> type;
    string key1, key2;
    cin >> key1 >> key2;
    constexpr int UNION = 0, QUERY = 1;
    if (type == UNION) {
      s.unionSet(key1, key2);
    } else {  // type == QUERY
      cout << (s.querySet(key1, key2) ? "yes" : "no") << endl;
    }
  }
}
