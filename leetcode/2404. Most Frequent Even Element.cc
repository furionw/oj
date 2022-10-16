// Date: 2022-10-15
class Solution {
 public:
  int mostFrequentEven(vector<int>& nums) {
    int res = numeric_limits<int>::max();
    int maxCnt = 0;
    unordered_map<int, int> cntByNum;
    for (int num : nums) {
      if (num & 1) {
        continue;
      }
      if (++cntByNum[num] > maxCnt
          || (cntByNum[num] == maxCnt && num < res)) {
        res = num;
        maxCnt = cntByNum[num];        
      }
    }
    return cntByNum.empty() ? -1 : res;
  }
};
