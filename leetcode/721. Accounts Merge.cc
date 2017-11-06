// Copyright 2017 Qi Wang
// Date: 2017-11-06
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
 
  T FindSet(const T& key) {
    Node<T>& node = nodes_[key];
    if (node.parent != key) {
      return node.parent = FindSet(node.parent);
    } else {
      return node.parent;
    }
  }
 
 protected:
  NodesType nodes_;
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
 
class Solution {
 public:
  vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
    unordered_map<string, string> email_to_person_map;
    DisjointSet<string> s;
    for (const auto& row : accounts) {
      if (row.size() <= 1) continue;
      email_to_person_map[row[1]] = row[0];
      s.UnionSet(row[1], row[1]);
      for (int i = 2; i < row.size(); ++i) {
        email_to_person_map[row[i]] = row[0];
        s.UnionSet(row[i - 1], row[i]);
      }
    }
    unordered_map<string, set<string>> email_to_emails_map;
    for (const auto& row : accounts) {
      for (int i = 1; i < row.size(); ++i) {
        email_to_emails_map[s.FindSet(row[i])].insert((row[i]));
      }
    }
    vector<vector<string>> result;
    for (auto& p : email_to_emails_map) {
      vector<string> row;
      row.push_back(email_to_person_map[*p.second.begin()]);
      row.resize(p.second.size() + 1);
      copy(p.second.begin(), p.second.end(), row.begin() + 1);
      result.push_back(move(row));
    }
    return result;
  }
};
