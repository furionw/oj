// Copyright 2016 Qi Wang
// Date: 2016-10-20
#include <iostream>

using std::cin; using std::cout; using std::endl;

struct Node {
  int parent;
  int relation = 0;
};

constexpr int MAXN = 5e4 + 1;
Node nodes[MAXN];

int find(int idx) {
  if (nodes[idx].parent == idx) {
    return idx;
  } else {
    int temp = nodes[idx].parent;
    nodes[idx].parent = find(nodes[idx].parent);
    nodes[idx].relation = (nodes[idx].relation + nodes[temp].relation) % 3;
    return nodes[idx].parent;
  }
}

int main() {
  int n, k, res = 0;
  cin >> n >> k;
  while (k--) {
    int op, a1, a2;
    constexpr int SAME = 1, EAT = 2;
    cin >> op >> a1 >> a2;
    // trivial case
    if ((a1 > n || a2 > n) || (op == EAT && a1 == a2)) {
      ++res;
      continue;
    }
    // nontrivial case
    int s1 = find(a1), s2 = find(a2);    
    if (s1 != s2) {
      nodes[s2].parent = s1;
      nodes[s2].relation = 
    } else {
      // op == EAT
    }
  }
}
