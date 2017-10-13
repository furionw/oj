// Copyright 2017 Qi Wang
// Date: 2017-10-12
class Solution {
 public:
  vector<string> topKFrequent(vector<string>& words, int k) {
    unordered_map<string, int> word_to_freq_map;
    for (const string& word : words) {
      ++word_to_freq_map[word];
    }
    priority_queue<Pair, vector<Pair>, comp> pq;
    for (const auto& p : word_to_freq_map) {
      pq.emplace(p.second, p.first);
    }
    vector<string> result;
    for (int i = 0; i < k; ++i) {
      result.push_back(pq.top().second);
      pq.pop();
    }
    return result;
  }

 private:
  using Pair = pair<int, string>;
  struct comp {
    bool operator()(const Pair& lhs, const Pair& rhs) const {
      return lhs.first != rhs.first ? lhs.first < rhs.first
                                    : lhs.second > rhs.second;
    }
  };  
};
