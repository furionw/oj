// Date: 2017-04-08
int main() {
  int n = 50;
  vector<vector<bool>> dp(n + 1, vector<bool>(n + 1, false));
  // init
  for (int i = 1; i <= n; ++i)
    for (int j = i; j <= n; ++j)
      dp[i][j] = true;
  // begin
  for (int i = 1; i <= n; ++ i) {
    for (int j = 1; j <= (i - 1) >> 1; ++j) {
      bool win = true;
      for (int k = j; k >= 1 && win; --k) {
        auto begin = dp[i - j - k].begin() + 1;
        auto last = begin + k;
        win = k >= (i - j - k) || find(begin , last, true) != last;
      }
      dp[i][j] = win;
    }
  }
  for (int i = 2; i <= n; ++ i) {
    bool find = false;
    int maximal = -1;
    for (int j = (i - 1) >> 1; j >= 1 && !find; --j) {
      find = dp[i][j];
      maximal = j;
    }
    printf("%d: %d\n", i, find ? maximal : -1);
  }
}
