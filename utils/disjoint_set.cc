// Copyright 2016 Qi Wang
// Date: 2016-10-19
#include <unordered_map>
#include <vector>

using std::unordered_map;
using std::vector;

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
  inline void UnionSet(const T& key1, const T& key2) {
    T s1 = FindSet(key1), s2 = FindSet(key2);
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

  inline bool QuerySet(const T& key1, const T& key2) {
    return FindSet(key1) == FindSet(key2);
  }

 protected:
  NodesType nodes_;

 private:
  T FindSet(const T& key) {
    Node<T>& node = nodes_[key];
    if (node.parent != key) {
      return node.parent = FindSet(node.parent);
    } else {
      return node.parent;
    }
  }
};

template <class T>
class DisjointSet : public DisjointSetBase<T, unordered_map<T, Node<T>>> {
 public:
  inline void UnionSet(const T& key1, const T& key2) {
    // Note that both UnionSet and QuerySet need those two TryToMakeSet()
    TryToMakeSet(key1);
    TryToMakeSet(key2);
    DisjointSetBase<T, unordered_map<T, Node<T>>>::UnionSet(key1, key2);
  }

  inline bool QuerySet(const T& key1, const T& key2) {
    // Note that both UnionSet and QuerySet need those two TryToMakeSet()
    TryToMakeSet(key1);
    TryToMakeSet(key2);
    return DisjointSetBase<T, unordered_map<T, Node<T>>>::QuerySet(key1, key2);
  }

 private:
  inline void TryToMakeSet(const T& key) {
    // It's necessary to tell the compiler explicitly that the names are in
    // fact dependent on the instantiation of the parent, via using this->
    // Or we will get compilation error in g++
    if (this->nodes_.find(key) == this->nodes_.end())
      this->nodes_.emplace(key, key);
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

}
