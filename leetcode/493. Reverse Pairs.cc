// 2025-05-18
class Solution {
 public:
  int reversePairs(vector<int>& nums) {
    int result = 0;
    long long offset = -1LL * numeric_limits<int>::min();
    long long n = 1LL + numeric_limits<int>::max() - numeric_limits<int>::min();

    for (int i = nums.size() - 1; i >= 0; --i) {
      long long num = nums[i];
      // num = 6, num / 2 = 3, we want (-oo, 2]. i.e. half - 1
      // num = 5, num / 2 = 2, we want (-oo, 2]. i.e. half
      // num = 1, num / 2 = 0, we want (-oo, 0]. i.e. half

      // num = 0, num / 2 = 0, we want (-oo, -1]. i.e. half - 1

      // num = -3, num / 2 = -1, we want (-oo, -2]. i.e. half - 1
      // num = -2, num / 2 = -1, we want (-oo, -2]. i.e. half - 1
      // num = -1, num / 2 = 0, we want (-oo, -1]. i.e. half - 1
      long long comp = num / 2;
      if (num <= 0 || num % 2 == 0) {
        --comp;
      }
      result += q(n, n + comp + offset);
      inc(n + num + offset);
    }
    return result;
  }

 private:
  void inc(long long idx) {
    for (; idx > 0; idx /= 2) {
      ++t[idx]; 
    }
  }

  int q(long long l, long long r) {
    int result = 0;
    while (l <= r) {
      if (l % 2 == 1) {
        result += t[l];
        l = l / 2 + 1;
      } else {
        l /= 2;
      }
      if (r % 2 == 0) {
        result += t[r];
        r = r / 2 - 1;
      } else {
        r /= 2;
      }
    }
    return result;
  }

  unordered_map<long long, int> t;
  vector<int> nums;
};
