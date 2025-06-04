// 2025-06-03
class Solution {
 public:
  bool canPartitionGrid(vector<vector<int>>& grid) {
    vector<uint64_t> nums1, nums2;
    uint64_t s = 0;
    for (int i = 0; i < grid.size(); ++i) {
      for (int num : grid[i]) {
        s += num;
      }
      nums1.push_back(s);
    }
    s = 0;
    for (int j = 0; j < grid[0].size(); ++j) {
      for (int i = 0; i < grid.size(); ++i) {
        s += grid[i][j];
      }
      nums2.push_back(s);
    }
    return canPartitionArray(nums1) || canPartitionArray(nums2);
  }

 private:
  bool canPartitionArray(const vector<uint64_t>& nums) {
    uint64_t s = nums.back();
    if (s % 2 == 1) {
      return false;
    }
    return binary_search(nums.begin(), nums.end(), s / 2);
  }
};
