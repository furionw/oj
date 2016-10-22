// Copyright 2016 Qi Wang
// Date: 2016-10-22
#include <cstdio>
#include <map>
#include <list>
#include <vector>
#include <queue>
#include <algorithm>

using std::pair;
using std::vector;

// Solution from LeetCode 207. Course Schedule
class Solution {
 public:
  bool canFinish(int numCourses, const vector<pair<int, int>>& prerequisites) {
    vector<std::list<int>> graph(numCourses + 1);
    vector<int> inDegree(numCourses + 1, 0);
    for (auto& p : prerequisites) {
      graph[p.first].push_back(p.second);
      ++inDegree[p.second];
    }
    std::queue<int> zeroInDegreeQ;
    for (int i = 1; i <= numCourses; ++i)
      if (inDegree[i] == 0) zeroInDegreeQ.push(i);
    while (!zeroInDegreeQ.empty()) {
      int u = zeroInDegreeQ.front();
      zeroInDegreeQ.pop();
      for (int v : graph[u])
        if (--inDegree[v] == 0) zeroInDegreeQ.push(v);
    }
    return std::all_of(inDegree.begin(), inDegree.end(), [](int degree) {
      return degree == 0;
    });
  }
};

int main() {
  Solution solution;
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, m;
    scanf("%d%d", &n, &m);
    vector<pair<int, int>> prerequisites;
    while (m--) {
      int a, b;
      scanf("%d%d", &a, &b);
      prerequisites.emplace_back(a, b);
    }
    printf(solution.canFinish(n, prerequisites) ? "Correct\n" : "Wrong\n");
  }
}
