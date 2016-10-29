// Copyright 2016 Qi Wang
// RMQ, segment tree, Range modification
// Date: 2016-10-29
#include <cstdio>

constexpr int MAXN = 1e5 + 5;
constexpr int NON_TAG = 0;
constexpr int ROOT = 1;
struct Node {
  int len;
  int val;
  int lazyTag;
};
Node nodes[MAXN << 2];

inline int left(int u) { return u << 1; }
inline int right(int u) { return left(u) | 1; }
// Called by build() and modify()
inline void pushUp(int u) {
  nodes[u].val = nodes[left(u)].val + nodes[right(u)].val;
}

inline void pushDown(int u) {
  if (nodes[u].lazyTag != NON_TAG) {
    int left = ::left(u);
    int right = ::right(u);
    nodes[left].lazyTag = nodes[right].lazyTag = nodes[u].lazyTag;
    nodes[left].val = nodes[u].lazyTag * nodes[left].len;
    nodes[right].val = nodes[u].lazyTag * nodes[right].len;
    nodes[u].lazyTag = NON_TAG;
  }
}

void modify(int qBegin, int qEnd, int val, int begin, int end, int u) {
  if (qBegin == begin && qEnd == end) {
    nodes[u].lazyTag = val;
    nodes[u].val = val * nodes[u].len;
  } else {
    pushDown(u);
    int mid = (begin + end) >> 1;
    if (qEnd <= mid) {
      modify(qBegin, qEnd, val, begin, mid, left(u));
    } else if (qBegin >= mid + 1) {
      modify(qBegin, qEnd, val, mid + 1, end, right(u));
    } else {
      modify(qBegin, mid, val, begin, mid, left(u));
      modify(mid + 1, qEnd, val, mid + 1, end, right(u));
    }
    pushUp(u);
  }
}

int query(int qBegin, int qEnd, int begin, int end, int u) {
  if (qBegin == begin && qEnd == end) {
    return nodes[u].val;
  } else {
    pushDown(u);
    int mid = (begin + end) >> 1;
    if (qEnd <= mid) {
      return query(qBegin, qEnd, begin, mid, left(u));
    } else if (qBegin >= mid + 1) {
      return query(qBegin, qEnd, mid + 1, end, right(u));
    } else {
      return query(qBegin, mid, begin, mid, left(u))
          + query(mid + 1, qEnd, mid + 1, end, right(u));
    }
  }
}

void build(int begin, int end, int u) {
  if (begin == end) {
    nodes[u].val = 1;
    nodes[u].len = 1;
  } else {
    int mid = (begin + end) >> 1;
    build(begin, mid, left(u));
    build(mid + 1, end, right(u));
    pushUp(u);
    nodes[u].len = nodes[left(u)].len + nodes[right(u)].len;
  }
  nodes[u].lazyTag = NON_TAG;
}

int main() {
  int t, n, q;
  scanf("%d", &t);
  for (int i = 1; i <= t; ++i) {
    scanf("%d%d", &n, &q);
    build(1, n, 1);
    while (q--) {
      int l, r, val;
      scanf("%d%d%d", &l, &r, &val);
      modify(l, r, val, 1, n, ROOT);
    }
    printf("Case %d: The total value of the hook is %d.\n",
        i, query(1, n, 1, n, ROOT));
  }
}
