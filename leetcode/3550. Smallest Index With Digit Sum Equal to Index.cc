// 2025-05-17
class Solution {
 public:
  int smallestIndex(vector<int>& nums) {
    for (int i = 0; i < nums.size(); ++i) {
      if (f(nums[i]) == i) {
        return i;
      }
    }
    return -1;
  }
    
 private:
  int f(int num) {
    int result = 0;
    for (; num > 0; num /= 10) {
      result += num % 10;
    }
    return result;
  }
};