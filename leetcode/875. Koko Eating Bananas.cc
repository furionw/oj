// Date: 2022-12-14
// Method 2
// Refer to: https://leetcode.com/problems/koko-eating-bananas/solutions/152324/java-c-python-binary-search/
class Solution {
 public:
  int minEatingSpeed(vector<int>& piles, int h) {
    int l = 1;
    // This can be max(piles) too.
    // The point is
    //   - piles.length <= h <= 1e9 &&
    //   - 1 <= piles[i] <= 1e9
    int r = 1e9;
    while (l < r) {
      int m = (l + r) >> 1;
      int cnt = 0;
      for (int p : piles) {
        cnt += (p + m - 1) / m;
      }
      if (cnt > h) {
        l = m + 1;
      } else {
        r = m;
      }
    }
    return l;
  }
};

// Date: 2022-12-14
// Method 1
class Solution {
 public:
  int minEatingSpeed(vector<int>& piles, int h) {
    size_t sum = accumulate(piles.begin(), piles.end(), 0L);
    size_t l = (sum + h - 1) / h;
    size_t r = sum; // ?
    int res = -1;
    while (l <= r) {
      size_t mid = (l + r) >> 1;
      int cnt = count(piles, mid);
      if (cnt > h) {
        l = mid + 1;
      } else {
        res = mid;
        r = mid - 1;
      }
    }
    return res;
  }

 private:
  int count(const vector<int>& piles, size_t k) {
    int cnt = 0;
    for (int p : piles) {
      cnt += (p + k - 1) / k;
    }
    return cnt;
  }
};
