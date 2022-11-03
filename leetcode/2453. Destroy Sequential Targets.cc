// Date: 2022-11-02
// Method 2
class Solution {
 public:
  int destroyTargets(vector<int>& nums, int space) {
    unordered_map<int, list<int>> remainderToNumsMap; 
    int maxCnt = 0;
    unordered_set<int> remainders;
    for (int num : nums) {
      int remainder = num % space;
      auto& v = remainderToNumsMap[remainder];
      v.push_back(num);
      maxCnt = max(maxCnt, int(v.size()));
    }
    int result = numeric_limits<int>::max();
    for (const auto& [_, v]: remainderToNumsMap) {
      if (v.size() == maxCnt) {
        for (int num : v) {
          result = min(result, num);
        }
      }
    }
    return result;
  }
};

// Method 1
class Solution {
 public:
  int destroyTargets(vector<int>& nums, int space) {
    unordered_map<int, int> remainderToCntMap; 
    int maxCnt = 0;
    unordered_set<int> remainders;
    for (int num : nums) {
      int remainder = num % space;
      if (++remainderToCntMap[remainder] == maxCnt) {
        remainders.insert(remainder);
      } else if (remainderToCntMap[remainder] > maxCnt) {
        maxCnt = remainderToCntMap[remainder];
        remainders.clear();
        remainders.insert(remainder);
      }
    }
    int result = numeric_limits<int>::max();
    for (int num : nums) {
      int remainder = num % space;
      if (remainders.count(remainder)) {
        result = min(result, num);
      }
    }
    return result;
  }
};
