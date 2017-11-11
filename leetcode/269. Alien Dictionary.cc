// Copyright 2017 Qi Wang
// Date: 2017-11-11
class Solution {
 public:
  string alienOrder(vector<string>& words) {
    unordered_map<char, int> char_to_in_degree_map;
    unordered_map<char, unordered_set<char>> char_to_edges_map;
    for (int i = 0; i < words.size(); ++i) {
      for (int k = 0, j = i + 1; j < words.size() && k < words[i].size() &&
                                 k < words[j].size();
           ++k) {
        if (words[i][k] == words[j][k]) continue;
        if (char_to_edges_map[words[i][k]].count(words[j][k]) == 0) {
          ++char_to_in_degree_map[words[j][k]];
          char_to_edges_map[words[i][k]].insert(words[j][k]);
        }
        break;
      }
      for (char c : words[i]) {
        char_to_in_degree_map[c] = char_to_in_degree_map[c];
      }
    }
    string result;
    while (!char_to_in_degree_map.empty()) {
      char u = 0;
      for (const auto& p : char_to_in_degree_map) {
        if (p.second == 0) {
          u = p.first;
          break;
        }
      }
      if (u == 0) return "";
      result += u;
      char_to_in_degree_map.erase(u);
      for (char v : char_to_edges_map[u]) {
        --char_to_in_degree_map[v];
      }
    }
    return result;
  }
};

// Date: 2017-08-03
class Solution {
 public:
  string alienOrder(vector<string>& words) {
    bool edges[26][26];
    memset(edges, 0, sizeof edges);
    bool vi[26];
    memset(vi, 0, sizeof vi);
    int in_degree[26];
    memset(in_degree, 0, sizeof in_degree);
    for (int i = 0; i < words.size(); ++i) {
      for (char c : words[i]) {
        vi[c - 'a'] = true;
      }
      if (i + 1 == words.size()) {
        break;
      }
      for (int j = 0; j < words[i].size() && j < words[i + 1].size();
          ++j) {
        if (words[i][j] != words[i + 1][j]) {
          int idx1 = words[i][j] - 'a', idx2 = words[i + 1][j] - 'a';
          if (edges[idx2][idx1]) {
            return "";
          } else if (!edges[idx1][idx2]) {
            edges[idx1][idx2] = true;
            ++in_degree[idx2];
          }
          break;
        }
      }
    }
    int cnt = count(vi, vi + 26, true);
    string result;
    while (true) {
      int u = -1;
      for (int i = 0; i < 26; ++i) {
        if (vi[i] && in_degree[i] == 0) {
          in_degree[i] = -1;
          u = i;
          break;
        }
      }
      if (u == -1) {
        break;
      }
      result += u + 'a';
      for (int v = 0; v < 26; ++v) {
        in_degree[v] -= edges[u][v];
      }
    }
    return result.size() == cnt ? result : "";
  }
};

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
