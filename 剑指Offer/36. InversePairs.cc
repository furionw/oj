// Copyright 2017 Qi Wang
// Date: 2017-04-13
class Solution {
 public:
  int InversePairs(vector<int> data) {
    int cnt = 0;
    MergeSort(data, cnt);
    return cnt;
  }

 private:
  vector<int> MergeSort(const vector<int>& data, int& cnt) const {
    if (data.size() == 1) return data;
    int mid = data.size() >> 1;
    auto a = MergeSort(vector<int>(data.begin(), data.begin() + mid), cnt);
    auto b = MergeSort(vector<int>(data.begin() + mid, data.end()), cnt);
    return Merge(a, b, cnt);
  }

  vector<int> Merge(const vector<int>& a, const vector<int>& b, int& cnt)
      const {
    vector<int> result;
    int i = 0, j = 0;
    while (i < a.size() && j < b.size()) {
      if (a[i] > b[j]) {
        result.push_back(b[j++]);
      } else {
        cnt = (cnt + j) % DIVISOR;
        result.push_back(a[i++]);
      }
    }
    // Use loop instead of * here in case of overflow
    while (i < a.size()) {
      cnt = (cnt + b.size()) % DIVISOR;
      result.push_back(a[i++]);
    }
    while (j < b.size()) result.push_back(b[j++]);
    return result;
  }

  static constexpr int DIVISOR = 1000000007;
};
