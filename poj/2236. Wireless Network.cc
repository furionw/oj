// Copyright 2017 Qi Wang
// Date: 2017-05-25
#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

const int N_MAX = 1005;
int s[N_MAX];
int r[N_MAX];
bool repaired[N_MAX];
int pos[N_MAX][2];
vector<int> neighbor[N_MAX];
int n, d;

inline int Square(int num) { return num * num; }

inline int Dist(int i, int j) {
  return Square(pos[i][0] - pos[j][0]) + Square(pos[i][1] - pos[j][1]);
}

int Find(int p) {
  return s[p] == p ? p : s[p] = Find(s[p]);
}

bool Union(int p, int q) {
  int p_root = Find(p), q_root = Find(q);
  if (p_root == q_root) {
    return true;
  } else {
    // p_root becomes the root
    if (r[p_root] > r[q_root]) {
      s[q_root] = p_root;
    // q_root becomes the root
    } else {
      s[p_root] = q_root;
      if (r[q_root] == r[p_root]) ++r[q_root];
    }
    return false;
  }
}

int main() {
  scanf("%d%d", &n, &d);
  for (int i = 1; i <= n; ++i) {
    s[i] = i;
    scanf("%d%d", pos[i], pos[i] + 1);
  }
  d *= d;
  for (int i = 1; i <= n; ++i)
    for (int j = i + 1; j <= n; ++j)
      if (Dist(i, j) <= d) {
        neighbor[i].push_back(j);
        neighbor[j].push_back(i);
      }
  char op;
  int p, q;
  getchar();
  while (scanf("%c", &op) != EOF) {
    if (op == 'O') {
      scanf("%d", &p);
      repaired[p] = true;
      for (size_t i = 0; i < neighbor[p].size(); ++i)
        if (repaired[neighbor[p][i]])
          Union(p, neighbor[p][i]);
    } else {
      scanf("%d%d", &p, &q);
      printf(Find(p) == Find(q) ? "SUCCESS\n" : "FAIL\n");
    }
    getchar();
  }
}
