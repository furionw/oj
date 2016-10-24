// Copyright 2016 Qi Wang
// Date: 2016-10-24
#include <iostream>
#include <climits>
#include <vector>
#include <list>
#include <algorithm>

using std::cin; using std::endl; using std::cout;

inline int idx(int i, int j, int s) {
  return i * s + j;
}

int dfs(int u, const std::vector<std::list<int>>& roads) {
  int res = 1;
  for (int v : roads[u])
    res = std::max(dfs(v, roads));
  return res;
}

int main() {
  int t;
  cin >> t;
  for (int tt = 1; i <= t; ++tt) {
    // input
    int s;
    cin >> s;
    std::vector<int> nums(s * s);
    for (int i = 0; i < s * s; ++i)
      cin >> nums[i];
    // construct roads
    std::vector<std::list<int>> roads(s * s);
    for (int i = 0; i < s; ++i)
      for (int j = 0; j < s; ++j) {
        int curIdx = idx(i, j);
        if (i > 0) {
          int nextIdx = idx(i - 1, j);
          // check cpplint with this line plz
          if (nums[nextIdx] == nums[curIdx] + 1) roads[curIdx].push_back(nextIdx);
        }
        if (i + 1 < s) {
          int nextIdx = idx(i + 1, j);
          if (nums[nextIdx] == nums[curIdx] + 1)
            roads[curIdx].push_back(nextIdx);
        }
        if (j > 0) {
          int nextIdx = idx(i, j - 1);
          if (nums[nextIdx] == nums[curIdx] + 1)
            roads[curIdx].push_back(nextIdx);
        }
        if (j + 1 < s) {
          int nextIdx = idx(i, j + 1);
          if (nums[nextIdx] == nums[curIdx] + 1)
            roads[curIdx].push_back(nextIdx);
        }
      }
    int roomNum, max = INT_MIN;
    for (int i = 0; i < s * s; ++i) {
      int cur = dfs(i, roads);
      if (cur > max) {
        max = cur;
        roomNum = i;
      }
    }
    cout << "Case #" << tt << ": " << roomNum + 1 << " " << max << endl;
  }
}
