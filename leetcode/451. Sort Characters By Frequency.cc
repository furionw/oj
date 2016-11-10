// Copyright 2016 Qi Wang
// Google & Amazon
// Note that it seems that method 1 and method 2 have the same perfomance.
// However, do use "unordered_map" to boost up, instead of "map"
// Method 2 with priority_queue
class Solution {
 public:
  string frequencySort(string s) {
    unordered_map<char, int> charToCnt;
    for (char c : s)
      ++charToCnt[c];
    priority_queue<pair<int, char>> q;
    for (const auto& p : charToCnt)
      q.emplace(p.second, p.first);
    int offset = 0;
    for (; !q.empty(); q.pop()) {
      const auto& p = q.top();
      fill(s.begin() + offset, s.begin() + offset + p.first, p.second);
      offset += p.first;
    }
    return s;
  }
};

// Method 1 with map
// Date: 2016-11-09
class Solution {
 public:
  string frequencySort(string s) {
    unordered_map<char, int> charToCnt;
    for (char c : s)
      ++charToCnt[c];
    map<int, list<char>, greater<int>> cntToChars;
    for (const auto& p : charToCnt)
      cntToChars[p.second].push_back(p.first);
    int offset = 0;
    for (const auto& p : cntToChars)
      for (char c : p.second) {
        fill(s.begin() + offset, s.begin() + offset + p.first, c);
        offset += p.first;
      }
    return s;
  }
};
