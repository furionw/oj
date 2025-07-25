// 2025-05-29
// Merge sort. Refer to the Editorial
class Solution {
 public:
  int reversePairs(vector<int>& nums) {
    return mergeCount(0, nums.size() - 1, nums);
  }

  int mergeCount(int l, int r, vector<int>& nums) {
    if (l >= r) {
      return 0;
    }
    int mid = (l + r) >> 1;
    int count = mergeCount(l, mid, nums) + mergeCount(mid + 1, r, nums);
    for (int i = l, j = mid + 1; i <= mid; ++i) {
      for (; j <= r && nums[i] > 2LL * nums[j]; ++j) {}
      count += j - (mid + 1);
    }
    merge(l, r, nums);
    return count;
  }

  void merge(int l, int r, vector<int>& nums) {
    int mid = (l + r) >> 1;
    int i = l;
    int j = mid + 1;
    vector<int> temp;
    temp.reserve(j - i + 1);
    while (i <= mid && j <= r) {
      if (nums[i] < nums[j]) {
        temp.push_back(nums[i]);
        ++i;
      } else {
        temp.push_back(nums[j]);
        ++j;
      }
    }
    for (; i <= mid; ++i) {
      temp.push_back(nums[i]);
    }
    for (; j <= r; ++j) {
      temp.push_back(nums[j]);
    }
    move(temp.begin(), temp.end(), nums.begin() + l);
  }
};

// 2025-05-18
// Very slow...
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
