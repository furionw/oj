// Copyright 2017 Qi Wang
// Date: 2017-04-07
class Solution {
 public:
  int GetNumberOfK(vector<int> data ,int k) {
    if (data.empty()) return 0;
    return BinarySearch(data, k + 0.5) - BinarySearch(data, k - 0.5);
  }

 private:
  int BinarySearch(const vector<int>& data, float k) const {
    int l = 0, r = data.size() - 1, mid;
    while (l <= r) {
      mid = (l + r) >> 1;
      if (data[mid] < k) {
        l = mid + 1;
      } else {
        r = mid - 1;
      }
    }
    return data[mid] < k ? mid : mid - 1;
  }
};
