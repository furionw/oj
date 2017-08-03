// Copyright 2017 Qi Wang
// Date: 2017-08-02
// O(nlgn) with sort
// The solution on 2016-10-25 is more efficient
class Solution {
 public:
  int hIndex(vector<int>& citations) {
    if (citations.empty()) {
      return 0;
    }
    sort(citations.begin(), citations.end());
    if (citations.front() >= citations.size()) {
      return citations.size();
    }
    for (int h_index = citations.size() - 1; h_index >= 1; --h_index) {
      if (citations[citations.size() - h_index] >= h_index &&
          citations[citations.size() - h_index - 1] <= h_index) {
        return h_index;
      }
    }
    return 0;
  }
};

// Date: 2016-10-25
// Last modified: 2017-01-04
// O(n)
class Solution {
 public:
  int hIndex(vector<int>& citations) {
    vector<int> cnt(citations.size() + 1, 0);
    for (int citation : citations)
      ++cnt[citation <= citations.size() ? citation : citations.size()];
    int sum = 0;
    for (int i = citations.size(); i >= 0; --i)
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
