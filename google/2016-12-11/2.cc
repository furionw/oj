// Copyright 2016 Qi Wang
// Date: 2016-12-11
#include <algorithm>

struct Triple {
  Triple(bool v, int c, int r) : valid(v), cnt(c), res(r) {}
  bool valid;
  int cnt;
  int res;
};

Triple dfs(int A, int B, tree * T) {
  // nullptr
  if (!T) return Triple(true, 0, 0);
  // non nullptr
  auto lAns = dfs(A, B, T->l);
  auto rAns = dfs(A, B, T->r);
  if (lAns.valid && rAns.valid && A <= T->x && T->x <= B) {
    int cnt = lAns.cnt + rAns.cnt + 1;
    // Note that res equals to cnt, so we don't bother calculating it here
    return Triple(true, cnt, cnt);
  } else {
    // We don't care the cnt any more
    return Triple(false, -1, std::max(lAns.res, rAns.res));
  }
}

int solution(int A, int B, tree * T) {
  return dfs(A, B, T).res;
}

// test case
// (1, 10, (1, None, (2, None, (3, None, (4, None, None)))))
