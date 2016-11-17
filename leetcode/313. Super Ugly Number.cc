// Copyright 2016 Qi Wang
// Method 1
// Date: 2016-11-17
class Solution {
 public:
  int nthSuperUglyNumber(int n, vector<int>& primes) {
    vector<int> idxs(primes.size(), 0), ugly(n, INT_MAX);
    ugly[0] = 1;
    for (int i = 1; i < n; ++i) {
      for (size_t j = 0; j < primes.size(); ++j)
        ugly[i] = min(ugly[i], ugly[idxs[j]] * primes[j]);
      for (size_t j = 0; j < primes.size(); ++j)
        idxs[j] += ugly[idxs[j]] * primes[j] == ugly[i];
    }
    return ugly[n - 1];
  }
};
