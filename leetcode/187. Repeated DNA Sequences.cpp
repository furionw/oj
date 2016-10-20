// Copyright 2016 Qi Wang

// Map
// Date: 2016-09-27
class Solution {
 public:
  vector<string> findRepeatedDnaSequences(string s) {
    unordered_map<string, int> cnt;
    for (size_t i = 0; i + 10 <= s.size(); ++i)
      ++cnt[s.substr(i, 10)];
    vector<string> res;
    for (auto& seq : cnt)
      if (seq.second > 1) res.push_back(seq.first);
    return res;
  }
};

// KMP
// Complexity:
//   - time: O(n*(n+m)) = O(n^2) while m = 10
// Date: 2016-09-27
class Solution {
 public:
  vector<string> findRepeatedDnaSequences(string s) {
    for (size_t i = 0; i + 11 <= s.size(); ++i)
      updateMatchSet(s, i + 1, s.substr(i, 10));
    return vector<string>(matches.begin(), matches.end());
  }

 private:
  // KMP
  void updateMatchSet(const string& s, size_t start, const string& p) {
    auto pi = computePrefixFunction(p);
    int q = 0;
    for (size_t i = start; i < s.size(); ++i) {
      while (q != 0 && s[i] != p[q]) q = pi[q - 1];
      q += p[q] == s[i]? 1: 0;
      if (q == p.size()) {
        matches.insert(p);
        return;
      }
    }
  }

  // auxiliary function
  vector<int> computePrefixFunction(const string& p) {
    vector<int> pi(p.size(), 0);
    for (size_t i = 1; i < p.size(); ++i) {
      int q = pi[i - 1];
      while (q != 0 && p[q] != p[i]) q = pi[q - 1];
      pi[i] = q + (p[q] == p[i]? 1: 0);
    }
    return pi;
  }

  unordered_set<string> matches;
};
