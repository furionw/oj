// Copyright 2017 Qi Wang
// Date: 2017-07-06
// Method 2
class Solution {
 public:
  int findCelebrity(int n) {
    if (n < 1) return -1;
    list<int> candidates;
    for (int i = 0; i < n; ++i) candidates.push_back(i);
    while (candidates.size() > 1) {
      int front = candidates.front();
      candidates.pop_front();
      bool remain_front = true;
      for (auto it = candidates.begin(); it != candidates.end();) {
        remain_front = remain_front && ValidCandidate(front, *it);
        if (ValidCandidate(*it, front)) {
          ++it;
        } else {
          it = candidates.erase(it);
        }
      }
      if (remain_front) candidates.push_back(front);
    }
    if (candidates.empty()) return -1;
    bool celebrity = true;
    int candidate = candidates.front();
    for (int i = 0; celebrity && i < n; ++i)
      if (candidate != i)
        celebrity = ValidCandidate(candidate, i);
    return celebrity ? candidate : -1;
  }

 private:
   bool ValidCandidate(int candidate, int other) const {
     return knows(other, candidate) && !knows(candidate, other);
   };
};

// Date: 2017-07-06
// Method 1
class Solution {
 public:
  int findCelebrity(int n) {
    if (n < 1) return -1;
    vector<int> in_degree(n, 0), out_degree(n, 0);
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < n; ++j)
        if (i != j && knows(i, j))
          ++out_degree[i], ++in_degree[j];
    for (int i = 0; i < n; ++i)
      if (n - 1 == in_degree[i] && 0 == out_degree[i])
        return i;
    return -1;
  }
};
