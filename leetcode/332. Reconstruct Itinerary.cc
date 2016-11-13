// Copyright 2016 Qi Wang
// Date: 2016-11-13
class Solution {
 private:
  using Map = unordered_map<string, map<string, int>>;

 public:
  vector<string> findItinerary(vector<pair<string, string>> tickets) {
    Map ts;
    for (const auto& ticket : tickets)
      ++ts[ticket.first][ticket.second];
    vector<string> res {"JFK"};
    dfs(ts, tickets.size() + 1, res);
    return res;
  }

 private:
  void dfs(Map& tickets, size_t expectedSz, vector<string>& vtOut) const {
    string cur = vtOut.back();
    for (auto& p : tickets[cur]) {
      if (p.second == 0) continue;
      vtOut.push_back(p.first);
      // decrement the counter
      --p.second;
      dfs(tickets, expectedSz, vtOut);
      if (vtOut.size() == expectedSz) return;
      // restore the environment
      ++p.second;
      vtOut.pop_back();
    }
  }
};
