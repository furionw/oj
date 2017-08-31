// Copyright 2017 Qi Wang
// Date: 2017-08-30
// Case 1: 0 knows 1, 0 knows 2, 1 knows 2
class Solution {
 public:
  int findCelebrity(int n) {
    if (n < 0) return -1;
    int candidate = 0;
    for (int i = 1; i < n; ++i) {
      if (knows(candidate, i)) candidate = i;
    }
    for (int i = 0; i < n; ++i) {
      if (candidate != i &&
          (knows(candidate, i) || !knows(i, candidate))) return -1;
    }
    return candidate;
  }
};

// Date: 2017-08-15
// Refer to other's solution
class Solution {
 public:
  int findCelebrity(int n) {
    list<int> candidates;
    for (int i = 0; i < n; ++i) candidates.push_back(i);
    while (candidates.size() > 1) {
      int a = candidates.back(); candidates.pop_back();
      int b = candidates.back(); candidates.pop_back();
      bool a_knows_b = knows(a, b), b_knows_a = knows(b, a);
      if (!a_knows_b && b_knows_a) {
        candidates.push_back(a);
      } else if (a_knows_b && !b_knows_a) {
        candidates.push_back(b);
      }
    }
    if (candidates.empty()) return -1;
    int candidate = candidates.front();
    for (int i = 0; i < n; ++i) {
      if (i != candidate &&
          (knows(candidate, i) || !knows(i, candidate))) {
        return -1;
      }
    }
    return candidate;
  }
};

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
