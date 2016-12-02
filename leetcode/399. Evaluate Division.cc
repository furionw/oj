// Copyright 2016 Qi Wang
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
