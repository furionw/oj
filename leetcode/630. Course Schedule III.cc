// Copyright 2017 Qi Wang3
// Date: 2017-06-30
// Refer to: https://discuss.leetcode.com/topic/93712/python-straightforward-with-explanation
class Solution {
 public:
  int scheduleCourse(vector<vector<int>>& courses) {
    sort(courses.begin(), courses.end(), [](const vector<int>& lhs,
        const vector<int>& rhs) {
          return lhs[1] < rhs[1];
        });
    priority_queue<int> pq;
    int pos = 0;
    for (const auto& course : courses) {
      pos += course[0];
      pq.push(course[0]);
      if (pos > course[1]) {
        pos -= pq.top();
        pq.pop();
      }
    }
    return pq.size();
  }
};
