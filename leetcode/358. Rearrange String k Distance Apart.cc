// Copyright 2017 Qi Wang
// Date: 2017-09-10
// Case 1: "aabbcc", k = 3
class Solution {
 public:
  string rearrangeString(string s, int k) {
    if (k <= 1) return s;
    priority_queue<pair<int, char>> pq;
    int cnts[26];
    memset(cnts, 0, sizeof cnts);
    for (char c : s) ++cnts[c - 'a'];
    for (int i = 0; i < 26; ++i) {
      if (cnts[i] != 0) {
        pq.emplace(cnts[i], i + 'a');
      }
    }
    string result;
    while (!pq.empty()) {
      vector<pair<int, char>> temp;
      int i = 0;
      for (; i < k && !pq.empty(); ++i) {
        auto p = pq.top(); pq.pop();
        if (p.first > 1) temp.emplace_back(p.first - 1, p.second);
        result += p.second;
      }
      if (i == k) {
        for (const auto& p : temp) {
          pq.push(p);
        }
      } else if (temp.empty()) {
        return result;
      } else {
        return "";
      }
    }
    return result;
  }
};