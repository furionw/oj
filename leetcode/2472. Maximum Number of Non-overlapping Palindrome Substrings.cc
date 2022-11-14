// Date: 2022-11-12
class Solution {
 public:
  int maxPalindromes(string s, int k) {
    vector<vector<bool>> mem(
        s.size(),
        vector<bool>(s.size(), false)
    );
    for (int mid = 0; mid < s.size(); ++mid) {
      gao(s, mid, mid, k, mem);
      gao(s, mid - 1, mid, k, mem);
    }
    
    vector<int> dp(s.size(), 0);
    for (int j = k - 1; j < s.size(); ++j) {
      if (j > 0) {
        dp[j] = dp[j - 1]; 
      }
      for (int i = j - k + 1; i >= 0; --i) {
        int prevMax = i == 0 ? 0 : dp[i - 1];
        dp[j] = max(dp[j], prevMax + mem[i][j]);
      }
    }
    return dp.back();
  }
  
 private:
  void gao(const string& s, int l, int r, int k, vector<vector<bool>>& mem) {
    for (; l >= 0 && r < s.size() && s[l] == s[r]; --l, ++r) {
      mem[l][r] = true;
    }
  }
};
