// 2025-06-20
class Solution {
 public:
  int waysToMakeFair(vector<int>& nums) {
    int n = nums.size();

    int totalOdd = 0;
    int totalEven = 0;
    for (int i = 0, odd = 0, even = 0; i < n; ++i) {
      totalOdd += (i % 2 == 1) ? nums[i]: 0;
      totalEven += (i % 2 == 0) ? nums[i]: 0;
    }

    int result = 0;
    for (int i = 0, preOdd = 0, preEven = 0, curOdd = 0, curEven = 0;
        i < n; ++i) {
      if (i > 0) {
        preOdd += (i % 2 == 0) ? nums[i - 1]: 0;
        preEven += (i % 2 == 1) ? nums[i - 1]: 0;
      }
      curOdd += (i % 2 == 1) ? nums[i]: 0;
      curEven += (i % 2 == 0) ? nums[i]: 0;      
      int lhs = preOdd + totalEven - curEven;
      int rhs = preEven + totalOdd - curOdd;
      if (lhs == rhs) {
        ++result;
      } 
    }
    return result;
  }
};
