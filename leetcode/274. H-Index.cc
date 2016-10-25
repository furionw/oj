// Copyright 2016 Qi Wang
// Date: 2016-10-25
// O(n)
class Solution {
 public:
  int hIndex(vector<int>& citations) {
    vector<int> cnt(citations.size() + 1, 0);
    for (int citation : citations)
      ++cnt[citation <= citations.size() ? citation : citations.size()];
    int sum = 0;
    for (int i = cnt.size() - 1; i >= 0; --i)
      if ((sum += cnt[i]) >= i) return i;
    return 0;  // soft the compiler
  }
};

// Date: 2016-10-25
// O(nlgn) with sort
class Solution {
 public:
  int hIndex(vector<int>& citations) {
    sort(citations.begin(), citations.end(), greater<int>());
    for (size_t i = 0; i < citations.size(); ++i)
      if (i >= citations[i]) return i;
    return citations.size();
  }
};
