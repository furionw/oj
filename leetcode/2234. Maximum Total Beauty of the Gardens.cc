// Date: 2022-12-01
class Solution {
 public:
  long long maximumBeauty(
      vector<int>& flowers, long long newF, int target, int full, int partial) {
    int n = flowers.size();
    sort(flowers.begin(), flowers.end());
    if (flowers[0] >= target) {
      return 1L * n * full;
    }
    vector<long long> cost(n, 0);
    for (int i = 1; i < n; ++i) {
      cost[i] = cost[i - 1] + (flowers[i] - flowers[i - 1]) * i;
    }
    int rbegin = n;
    for (; rbegin - 1 >= 0 && flowers[rbegin - 1] >= target; --rbegin) {}
    long long res = 0;
    for (int i = rbegin; i >= 0; --i) {
      long long candidate = 1L * (n - i) * full;
      if (i == 0) {
        return max(res, candidate);
      }      
      int idx = bSearch(cost, 0, i, newF);
      int minn = min(
          flowers[idx - 1] + (newF - cost[idx - 1]) / idx,
          static_cast<long long>(target - 1));
      candidate += 1L * minn * partial;
      res = max(res, candidate);
      if (i > 0 && newF >= target - flowers[i - 1]) {
        newF -= target - flowers[i - 1];
        flowers[i - 1] = target;
      } else {
        break;
      }
    }
    return res;
  }
  
 private:
  int bSearch(const vector<long long>& cost, int begin, int end, long long newF) {
    while (begin < end) {
      int m = (begin + end) >> 1;
      if (cost[m] == newF) {
        for (; m + 1 < end && cost[m] == cost[m + 1]; ++m) {}
        return m + 1;
      } else if (cost[m] > newF) {
        end = m;
      } else {
        begin = m + 1;
      }
    }
    return end; // begin == end now
  }
};
