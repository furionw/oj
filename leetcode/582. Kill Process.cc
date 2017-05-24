// Copyright 2017 Qi Wang
// Date: 2017-05-24
class Solution {
 public:
  vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill) {
    unordered_map<int, queue<int>> children;
    for (size_t i = 0; i < pid.size(); ++i)
      children[ppid[i]].push(pid[i]);
    vector<int> result;
    foo(kill, children, result);
    return result;
  }
 
 private:
  void foo(int kill, unordered_map<int, queue<int>>& children,
      vector<int>& result) const {
    result.push_back(kill);
    if (0 == children.count(kill)) return;
    auto& q = children[kill];
    while (!q.empty()) {
      kill = q.front();
      q.pop();
      foo(kill, children, result);
    }
  }
};
