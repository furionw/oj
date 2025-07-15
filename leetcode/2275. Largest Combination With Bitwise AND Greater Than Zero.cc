// 2025-07-10
class Solution {
 public:
  int largestCombination(vector<int>& nums) {
    vector<int> cnts(32, 0);
    for (int num : nums) {
      for (int idx = 0; num > 0; num >>= 1) {
        if (num & 1) {
          ++cnts[idx];
        }
        ++idx;
      }
    }
    return *max_element(cnts.begin(), cnts.end());
  }
};

// 2025-06-24
// TLE
class Solution {
 public:
  int largestCombination(vector<int>& nums) {
    unordered_map<int, int> cnts;
    cnts[numeric_limits<int>::max()] = 0;

    for (int num : nums) {
      unordered_map<int, int> newCnts;
      for (auto [k, v] : cnts) {
        int newK = k & num;
        newCnts[newK] = max(newCnts[newK], v + 1);
      }
      for (auto [k, v] : cnts) {
        newCnts[k] = max(newCnts[k], v);
      }
      cnts = move(newCnts);
    }

    int result = 0;
    cnts[0] = 0;
    for (auto [_, v] : cnts) {
      result = max(result, v);
    }
    return result;
  }
};
