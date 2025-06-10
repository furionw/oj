// 2025-06-09
class Solution {
 public:
  int numberOfWays(string s, string t, long long k) {
    auto idxs = strStr(s + s, t);

    if (idxs.empty()) {
      return 0;
    }

    int n = s.size();
    // refer to https://leetcode.com/problems/string-transformation/solutions/4024703/c-java-python-short-code-by-finding-the-pattern/?envType=company&envId=snowflake&favoriteSlug=snowflake-six-months
    // also check chatGPT
    long long fx = (f(n - 1, k) + k%2*2 - 1) * f(n, kMod - 2) % kMod;
    long long f0 = fx - (k%2*2 - 1);
    
    int numF0 = idxs[0] == 0;
    int numFx = idxs.size() - numF0;
    return (numF0 * f0 + numFx * fx) % kMod;
  }

 private:
  long long f(long long n, long long k) {
    if (k == 0) {
      return 1;
    }
    if (k == 1) {
      return n;
    } 
    long long fac = f(n, k / 2);
    long long result = fac * fac % kMod;
    return k % 2 == 1 ? (result * n % kMod) : result;
  }

  vector<int> strStr(string haystack, string needle) {
    int n = needle.size();

    // longest proper suffix
    vector<int> lps(n, 0);
    for (int i = 1, len = 0; i < n; ++i) {
      while (needle[i] != needle[len] && len > 0) {
        len = lps[len - 1];
      }
      if (needle[i] == needle[len]) {
        lps[i] = ++len;
      }
    }

    vector<int> result;
    int i = 0, j = 0;
    int m = haystack.size();
    for (; i < m - 1 && j < n; ++i) {
      while (haystack[i] != needle[j] && j > 0) {
        j = lps[j - 1];
      }
      if (haystack[i] == needle[j]) {
        ++j;
      }
      if (j == n) {
        result.push_back(i - n + 1);
        j = lps[j - 1];
      }
    }

    return result;
  }

  constexpr static int kMod = int(1e9 + 7);
};
