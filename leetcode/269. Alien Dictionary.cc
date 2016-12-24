// Copyright 2016 Qi Wang
// Date: 2016-12-24
class Solution {
 public:
  string alienOrder(vector<string>& words) {
    bool vi[SZ_] = {0};
    char inDegree[SZ_] = {0};
    bool dag[SZ_][SZ_] = {0};
    for (size_t i = 0; i < words.size(); ++i) {
      if (words[i].empty()) continue;
      for (char c : words[i]) vi[c - 'a'] = true;
      for (size_t j = i + 1; j < words.size(); ++j) {
        // words[i] is words[j]'s substr
        if (words[i] == words[j].substr(0, words[i].size())) continue;
        // words[j] is words[i]'s true substr
        if (words[j] == words[i].substr(0, words[j].size())) return "";
        auto edge = findEdge(words[i], words[j]);
        if (!dag[edge.first][edge.second]) {
          dag[edge.first][edge.second] = true;
          ++inDegree[edge.second];
        }
      }
    }
    queue<char> q;
    for (char i = 0; i < SZ_; ++i)
      if (vi[i] && inDegree[i] == 0)
        q.push(i);
    string res;
    while (!q.empty()) {  // non empty!!!
      char u = q.front();
      q.pop();
      res += (u + 'a');
      for (char v = 0; v < SZ_; ++v)
        if (dag[u][v] && --inDegree[v] == 0)  // dag should be used here!!!
          q.push(v);
    }
    return res.size() == accumulate(vi, vi + SZ_, 0, [](int sum, bool visited) {
      return sum + visited;
    }) ? res : "";
  }

 private:
  // w1 is not the substr of w2, so the pair must be found
  pair<char, char> findEdge(const string& w1, const string& w2) const {
    for (size_t i = 0; i < w1.size(); ++i)
      if (w1[i] != w2[i])
        return {w1[i] - 'a', w2[i] - 'a'};
    cerr << "Edge not found\n";
    return {-1, -1};  // comfort the compiler
  }

  static constexpr char SZ_ = 26;
};
