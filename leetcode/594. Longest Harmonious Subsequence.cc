// 2025-07-16
class Solution {
 public:
  int findLHS(vector<int>& nums) {
    map<int, int> cnts;
    for (int num : nums) {
      ++cnts[num];
    }
    auto it1 = cnts.begin();
    auto it2 = cnts.begin();
    int result = 0;
    for (++it2; it2 != cnts.end(); ++it2) {
      if (it1->first + 1 == it2->first) {
        result = max(result, it1->second + it2->second);
      }
      it1 = it2;
    }
    return result;
  }
};

// Date: 2017-05-22
class Solution {
 public:
  int findLHS(vector<int>& nums) {
    int result = 0;
    unordered_map<int, int> cnts;
    for (int num : nums) {
      ++cnts[num];
      if (cnts[num - 1] > 0)
        result = max(result, cnts[num - 1] + cnts[num]);
      if (cnts[num + 1] > 0)
        result = max(result, cnts[num] + cnts[num + 1]);
    }
    return result;
  }
};
