// 2025-06-23
// TLE
class Solution {
 public:
  long long kMirror(int k, int n) {
    long long result = 0;

    for (int i = 1, cnt = 0; cnt < n; ++i) {
      if (palindromic(::to_string(i)) && palindromic(to_string(i, k))) {
        result += i;
        ++cnt;
      }
    }

    return result;
  }

 private:
  bool palindromic(const string& s) {
    for (int i = 0, j = s.size() - 1; i < j; ++i, --j) {
      if (s[i] != s[j]) {
        return false;
      }
    }
    return true;
  }

  string to_string(int num, int k) {
    string result;
    for (; num != 0; num /= k) {
      result += (num % k + '0');
    }
    reverse(result.begin(), result.end());
    return result;
  }
};
