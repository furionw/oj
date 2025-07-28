// 2025-07-27
// Method 2: refer to others' solutions
class Solution {
 public:
  int maximumSum(vector<int>& nums) {
    vector<int> sums(82, -1);
    int result = -1;
    for (int num : nums) {
      int sum = 0;
      for (int i = num; i > 0; i /= 10) {
        sum += i % 10;
      }
      if (sums[sum] == -1) {
        sums[sum] = num;
      } else {
        result = max(result, sums[sum] + num);
        sums[sum] = max(sums[sum], num);
      }
    }
    return result;
  }
};

// 2025-07-27
// Method 1
class Solution {
 public:
  int maximumSum(vector<int>& nums) {
    unordered_map<int, multiset<int>> buckets;
    for (int num : nums) {
      int dSum = 0;
      for (int i = num; i > 0; i /= 10) {
        dSum += i % 10;
      }
      auto& bucket = buckets[dSum];
      bucket.insert(num);
      if (bucket.size() > 2) {
        bucket.erase(bucket.begin());
      }
    }

    int result = -1;
    for (const auto& [_, bucket] : buckets) {
      if (bucket.size() != 2) {
        continue;
      }
      auto it = bucket.begin();
      ++it;
      result = max(result, *bucket.begin() + *it);
    }
    return result;
  }
};
