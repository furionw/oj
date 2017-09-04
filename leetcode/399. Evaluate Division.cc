// Copyright 2017 Qi Wang
// Date: 2017-09-01
class Solution {
 public:
  vector<double> calcEquation(vector<pair<string, string>> equations,
      vector<double>& values, vector<pair<string, string>> queries) {
    unordered_map<string, list<pair<string, double>>> dist_tbl;
    int n = equations.size();
    for (int i = 0; i < n; ++i) {
      dist_tbl[equations[i].first].emplace_back(equations[i].second, values[i]);
      if (values[i] != 0) {
        dist_tbl[equations[i].second].emplace_back(equations[i].first,
                                                   1/ values[i]);
      }
    }
    int m = queries.size();
    vector<double> result(m, -1);
    for (int i = 0; i < m; ++i) {
      if (queries[i].first == queries[i].second &&
          dist_tbl.find(queries[i].first) != dist_tbl.end()) {
        result[i] = 1;
      } else {
        unordered_map<string, bool> visited;
        Dfs(queries[i].first, queries[i].second, &dist_tbl, &visited,
            1, &result[i]);
      }
    }
    return result;
  }
 
 private:
  bool Dfs(const string& a, const string& b,
           unordered_map<string, list<pair<string, double>>>* dist_tbl,
           unordered_map<string, bool>* visited,
           double prev, double* result) {
    (*visited)[a] = true;
    for (const auto& dist_pair : (*dist_tbl)[a]) {
      const string& next = dist_pair.first;
      double value = dist_pair.second;
      if (next == b) {
        *result = prev * value;
      } else if (!(*visited)[next] &&
                 Dfs(next, b, dist_tbl, visited, prev * value, result)) {
        return true;
      }
    }
    return false;
  }
};

// Date: 2016-12-02
class Solution {
 public:
  vector<double> calcEquation(vector<pair<string, string>> equations,
      vector<double>& values, vector<pair<string, string>> queries) {
    unordered_set<string> zeros;
    unordered_map<string, list<pair<string, double>>> edges;
    for (size_t i = 0; i < equations.size(); ++i) {
      if (values[i] == 0) {
        zeros.insert(equations[i].first);
      } else {
        edges[equations[i].first].emplace_back(equations[i].second, values[i]);
        edges[equations[i].second].emplace_back(equations[i].first, 1 / values[i]);
      }
    }
    vector<double> res;
    for (auto& query : queries) {
      if (zeros.find(query.first) != zeros.end()) {
        res.push_back(0);
      } else if (edges.find(query.first) == edges.end()) {
        res.push_back(-1);
      } else {
        res.push_back(dijkstra(query.first, query.second, edges));
      }
    }
    return res;
  }

 private:
  double dijkstra(const string& begin, const string& end, 
      unordered_map<string, list<pair<string, double>>>& edges) const {
    unordered_set<string> vi;
    unordered_map<string, double> values;
    queue<string> q;
    q.push(begin);
    values[begin] = 1;
    while (!q.empty()) {
      string cur = q.front();
      q.pop();
      vi.insert(cur);
      const double VALUE = values[cur];
      for (auto edge : edges[cur]) {
        // This value we have calculated before
        if (vi.find(edge.first) != vi.end()) continue;
        values[edge.first] = VALUE * edge.second;
        q.push(edge.first);
      }
    }
    double possibleRes = values[end];
    // We guarantee values[begin] non-zero, thus possibleRes won't be 0
    return possibleRes != 0 ? possibleRes : -1;
  }
};
