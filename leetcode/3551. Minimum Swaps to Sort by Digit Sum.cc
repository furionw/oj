// 2025-05-17
class Solution {
 public:
  int minSwaps(vector<int>& nums) {
    vector<int> vals = nums;
    vector<int> idxs = nums;
    for (int i = 0; i < idxs.size(); ++i) {
      idxs[i] = i;
      vals[i] = f(nums[i]);
    }
    sort(idxs.begin(), idxs.end(), [&](int i, int j) {
      return vals[i] != vals[j]
          ? vals[i] < vals[j]
          : nums[i] < nums[j];
    });
    int result = 0;
    for (int i = 0; i < idxs.size(); ++i) {
      while (idxs[i] != i) {
        swap(idxs[i], idxs[idxs[i]]);
        ++result;
      }
    }
    return result;
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
