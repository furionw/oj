// Copyright 2016 Qi Wang
// Date: 2016-10-29
#include <iostream>
#include <numeric>
#include <vector>
#include <algorithm>

using std::cin; using std::cout;
using std::vector;

inline int sum(const vector<int>::iterator& begin,
    const vector<int>::iterator& end) {
  return std::accumulate(begin, end, 0, [](int pre, int cur) {
    return pre + cur;
  });
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    // input and init
    int n, m;
    cin >> n >> m;
    vector<int> nums;
    int begin = 1, end;
    while (n--) {
      cin >> end;
      nums.push_back(end - begin);
      begin = end + 1;
    }
    if (end != 100) nums.push_back(100 - begin);
    // calculate result via greedy strategy
    int res = 0;
    if (m + 1 >= nums.size()) {
      res = 100;
    } else {
      for (int offset = 0; offset + m < nums.size(); ++offset)
        res = std::max(res,
            sum(nums.begin() + offset, nums.begin() + offset + m + 1) + m);
    }
    cout << res << '\n';
  }
}
