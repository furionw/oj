// Date: 2022-11-26
class Solution {
 public:
  int countSubarrays(vector<int>& nums, int k) {
    vector<int> d(nums.size(), 0);
    int kIdx = 0;
    for (size_t i = 0; i < nums.size(); ++i) {
      d[i] = nums[i] < k
          ? -1
          : (nums[i] > k ? 1 : 0);
      if (nums[i] == k) {
        kIdx = i;
      }
    }
    return foo(d, 0, nums.size(), 0) - foo(d, 0, kIdx, 0) - foo(d, kIdx +1, nums.size(), 0)
        + foo(d, 0, nums.size(), 1) - foo(d, 0, kIdx, 1) - foo(d, kIdx +1, nums.size(), 1);
  }
  
 private:
  size_t foo(const vector<int>& d, int begin, int end, int target) {
    size_t sum = 0;
    unordered_map<int, size_t> sumToCnt;
    size_t res = 0;
    for (int i = begin; i < end; ++i) {
      sum += d[i];
      if (sum == target) {
        ++res;
      }
      auto it = sumToCnt.find(sum - target);
      if (it != sumToCnt.end()) {
        res += it->second;
      }
      ++sumToCnt[sum];
    }
    return res;
  }
};
