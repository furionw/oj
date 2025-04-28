class Solution {
 public:
  int rangeSum(vector<int>& nums, int n, int left, int right) {
    vector<int> sums(n * (n + 1) / 2, 0);

    int idx = 0;
    for (int i = 0; i < n; ++i) {
      sums[idx] = nums[i];
      ++idx;
      for (int j = i + 1; j < n; ++j) {
        sums[idx] = sums[idx - 1] + nums[j];
        ++idx;
      }
    }
    
    auto gt = greater<int>{};
    make_heap(sums.begin(), sums.end(), gt);
    right = right - left + 1;
    for (; left > 1; --left) {
      pop_heap(sums.begin(), sums.end(), gt);
      sums.pop_back();
    }
    int sum = 0;
    for (; right > 0; --right) {
      sum = (sum + sums[0]) % int(1e9 + 7);
      pop_heap(sums.begin(), sums.end(), gt);
      sums.pop_back();
      --idx;
    }
    return sum;
  }
};
