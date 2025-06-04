// 2025-06-03
class Solution {
 public:
  long long maxScore(int n, vector<vector<int>>& edges) {
    assert(n > 1);
    if (n == 2) {
      return 2;
    }
    long long result = 0;
    long long lPrev = n, rPrev = n;
    for (long long l = n - 2, r = n - 1; l >= 1; l -= 2, r -= 2) {
      result += lPrev * l;
      lPrev = l;
      result += rPrev * r;
      rPrev = r;
    }
    if (n == edges.size()) {
      assert(n >= 3);
      result += (n % 2 == 1) ? 2 : 5;      
    } else if (n % 2 == 0) {
      result +=  3;
    }
    return result;
  }
};
