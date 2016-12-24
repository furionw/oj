// Copyright 2016 Qi Wang
// Date: 2016-12-24
class Solution {
 public:
  bool sequenceReconstruction(vector<int>& org, vector<vector<int>>& seqs) {
    // n : [1, 1e4]
    int n = static_cast<int>(org.size());
    bool vi[n];
    memset(vi, 0, sizeof vi);
    int inDegree[n];
    memset(inDegree, 0, sizeof inDegree);
    // consider using unordered_set
    unordered_set<int> dag[n];
    for (auto& seq : seqs) {
      for (size_t i = 0; i < seq.size(); ++i) {
        if (1 <= seq[i] && seq[i] <= n) {
          vi[seq[i] - 1] = true;
          if (i != 0 && dag[seq[i - 1] - 1].count(seq[i] - 1) == 0) {
            ++inDegree[seq[i] - 1];
            dag[seq[i - 1] - 1].insert(seq[i] - 1);
          }
        } else {
          return false;
        }
      }
    }
    if (any_of(vi, vi + n, [](bool visited) { return !visited; }))
      return false;
    memset(vi, 0, sizeof vi);
    int idx = 0;
    queue<int> q;
    for (int i = 0; i < n; ++i)
      if (inDegree[i] == 0)
        q.push(i);
    while (q.size() == 1) {
      int u = q.front();
      if (u + 1 != org[idx++]) return false;
      q.pop();
      vi[u] = true;
      for (int v : dag[u])
        if (--inDegree[v] == 0)
          q.push(v);
    }
    return idx == n;
  }
};
