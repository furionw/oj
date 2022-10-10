// Date: 2022-10-09
class Solution {
 public:
  int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
    return maybeXor(nums1, nums2.size()) ^ maybeXor(nums2, nums1.size());
  }
  
 private:
  int maybeXor(const vector<int>& nums, size_t otherSz) {
    if (otherSz % 2 == 0) {
      return 0;
    }
    return accumulate(nums.begin(), nums.end(), 0, [](int acc, int cur) {
      return acc ^ cur;
    });
  }
};
