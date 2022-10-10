// Date: 2022-10-09
class Solution {
 public:
  vector<int> goodIndices(vector<int>& nums, int k) {
    int n = nums.size();

    vector<bool> nonIncreasing(n, true);
    int updatedIdx = k - 1;
    for (int i = 0; i < n - k; ++i) {
      if (nums[i] < nums[i + 1]) {
        updatedIdx = max(updatedIdx, i + 1);
        while (updatedIdx + 1 <= i + k) {
          nonIncreasing[++updatedIdx] = false;
        }
      }
    }

    vector<bool> nonDecreasing(n, true);
    updatedIdx = n - k;
    for (int i = n - 1; i > k; --i) {
      if (nums[i] < nums[i - 1]) {
        updatedIdx = min(updatedIdx, i - 1);
        while (updatedIdx - 1 >= i - k) {
          nonDecreasing[--updatedIdx] = false;
        }
      }
    }
    
    vector<int> result;
    for (int i = k; i < n - k; ++i) {
      if (nonIncreasing[i] && nonDecreasing[i]) {
        result.push_back(i);
      }
    }
    return result;
  }
};
