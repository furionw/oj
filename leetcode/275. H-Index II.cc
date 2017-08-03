// Copyright 2017 Qi Wang
// Date: 2017-08-02
// Refer to the solution on 2016-10-25
class Solution {
 public:
  int hIndex(vector<int>& citations) {
    if (citations.empty()) {
      return 0;
    }
    int n = citations.size();
    int l = 0, r = n - 1, res = 0;
    while (l <= r) {
      int mid = (l + r) >> 1;
      if (citations[mid] >= n - mid) {
        res = n - mid;
        r = mid - 1;
      } else {
        l = mid + 1;
      }
    }
    return res;
  }
};

// Date: 2016-10-25
// O(lgn) time complexity
class Solution {
 public:
  int hIndex(vector<int>& citations) {
    int l = 0, r = citations.size() - 1, res = 0;
    while (l <= r) {
      int mid = (l + r) >> 1;
      if (pred(citations, mid)) {
        res = citations.size() - mid;
        r = mid - 1;
      } else {
        l = mid + 1;
      }
    }
    return res;
  }

 private:
  inline bool pred(const vector<int>& citations, int i) const {
    return citations[i] >= citations.size() - i;
  }
};

// Date: 2016-10-25
// O(n) time complexity
class Solution {
 public:
  int hIndex(vector<int>& citations) {
    if (citations.empty()) return 0;
    for (size_t i = 0; i < citations.size(); ++i)
      if (citations[i] >= citations.size() - i)
        return citations.size() - i;
    return 0;
  }
};
