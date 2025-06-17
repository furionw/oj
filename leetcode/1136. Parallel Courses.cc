// 2025-06-16
class Solution {
 public:
  int minimumSemesters(int n, vector<vector<int>>& relations) {
    vector<vector<int>> edges(n, vector<int>{});
    vector<int> inDegrees(n, 0);
    for (const auto& r : relations) {
      edges[r[0] - 1].push_back(r[1] - 1);
      ++inDegrees[r[1] - 1];
    }
    queue<int> courses;
    for (int i = 0; i < n; ++i) {
      if (inDegrees[i] == 0) {
        courses.push(i);
      }
    }
    int taken = 0;
    int semesters = 0;
    while (!courses.empty()) {
      queue<int> nextCourses;
      ++semesters;
      while (!courses.empty()) {
        int prev = courses.front();
        courses.pop();
        ++taken;
        for (int next : edges[prev]) {
          if (--inDegrees[next] == 0) {
            nextCourses.push(next);
          }
        }
      }
      courses = std::move(nextCourses);
    }
    return taken == n ? semesters : -1;
  }
};
