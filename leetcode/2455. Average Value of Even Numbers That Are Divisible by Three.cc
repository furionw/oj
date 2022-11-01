// Date: 2022-10-31
class Solution {
 public:
  int averageValue(vector<int>& nums) {
    int sum = 0;
    int cnt = 0;
    for (int num : nums) {
      if (num % 6 == 0) {
        sum += num;
        ++cnt;
      }
    }
    return cnt > 0 ? sum / cnt : 0;
  }
};
