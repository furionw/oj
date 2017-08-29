// Copyright 2017 Qi Wang
// Date: 2017-08-28
class Solution {
 public:
  int countPrimes(int n) {
    if (n == 1) return 0;
    vector<bool> is_prime(n, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i < n; ++i) {
      if (is_prime[i]) {
        for (int j = 2 * i; j < n; j += i) {
          is_prime[j] = false;
        }
      }
    }
    return count(is_prime.begin(), is_prime.end(), true);
  }
};
  
// Date: 2017-06-13
// Refer to the solution in 2015-08
// Method 2
class Solution {
 public:
  int countPrimes(int n) {
    if (n <= 2) return 0;
    vector<bool> prime(n, true);
    // slightly differ from the method 1
    for (int i = 2; i * i < n; ++i)
      if (prime[i])
        // slightly differ from the method 1
        for (int j = i * i; j <= n; j += i) prime[j] = false;
    return count(prime.begin() + 2, prime.end(), true);
  }
};

// Date: 2017-06-13
// Method 1
class Solution {
 public:
  int countPrimes(int n) {
    if (n <= 2) return 0;
    vector<bool> prime(n, true);
    for (int i = 2; i < n; ++i)
      if (prime[i])
        for (int j = 2 * i; j <= n; j += i) prime[j] = false;
    return count(prime.begin() + 2, prime.end(), true);
  }
};

// Date: 2015-08
class Solution 
{
public:
  int countPrimes(int n) 
  {
    if (n <= 1)
    {
      return 0;
    }

  bool prime[n];
  memset(prime, true, sizeof(prime));
  for (int i = 2; i * i < n; ++ i)
  {
    if (prime[i] == false)
    {
      continue;
    }
    for (int j = i * i; j < n; j += i)
    {
      prime[j] = false;
    }
  }
  return count_if(prime+2, prime+n, [](bool prime) -> bool { return prime;});
  }
};
