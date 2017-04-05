// Copyright 2017 Qi Wang
// Method 2
// Date: 2017-04-05
class Solution {
 public:
  int MoreThanHalfNum_Solution(vector<int> numbers) {
    int prev = -1, cnt = 0;
    for (int num : numbers) {
      if (cnt == 0) {
        prev = num;
        ++cnt;
      } else {
        prev == num ? ++cnt : --cnt;
      }
    }
    return (cnt > 0 &&
        count(numbers.begin(), numbers.end(), prev) > (numbers.size() >> 1))
        ? prev : 0;
  }
};

// Method 1
// Date: 2017-04-05
class Solution {
 public:
  int MoreThanHalfNum_Solution(vector<int> numbers) {
    unordered_map<int, int> cnts;
    for (int num : numbers) ++cnts[num];
    for (const auto& p : cnts)
      if (p.second > (numbers.size() >> 1))
        return p.first;
    return 0;
  }
};
