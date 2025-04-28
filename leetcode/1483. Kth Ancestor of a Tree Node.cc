// Date: 2025-04-27
class TreeAncestor {
 public:
  TreeAncestor(int n, vector<int>& parent) {
    int maxK = n - 1;
    int d = floor(log2(maxK)) + 1;
    dp = vector<vector<int>>(n, vector<int>(d, -1));
    for (size_t i = 0; i < parent.size(); ++i) {
      dp[i][0] = parent[i];
    }
    for (int j = 1; j < d; ++j) {
      for (int i = 1; i < n; ++i) {
        if (dp[i][j - 1] == -1) {
          continue;
        }
        dp[i][j] = dp[ dp[i][j - 1] ][j - 1];
      }
    }
  }
  
  int getKthAncestor(int node, int k) {
    if (k == 0) {
      return node;
    }
    // looking for index
    // k = 1 -> 0
    // k = 2 -> 1
    // k = 3 -> 1
    // k = 4 -> 2
    int power = log2(k); // floor
    if (power >= dp[node].size() || dp[node][power] == -1) {
      return -1;
    }
    return getKthAncestor(dp[node][power], k - pow(2, power));
  }

 private:
  vector<vector<int>> dp;
};

// case 1: [[7, [-1, 0, 0, 1, 1, 2, 2]], [3, 1], [5, 2], [6, 3]]
// ctor
// maxK = 6
// d = 2 + 1 = 3
// dp[?][0] = {-1, 0, 0, 1, 1, 2, 2};
// iter: j = 1
//   iter: i = 1
//     dp[?][1] = {0, 0, 0, 0, 0, 0, 0}
//   ...
//   iter: i = 3
//     dp[3][1] = dp[1][0] = 0
//   ...

// [5, [-1,0,0,0,3]],[1,5],[3,2],[0,1],[3,1],[3,5]]
// ctor
// maxK = 4
// d = 2 + 1 = 3
// dp[?][0] = {-1, 0, 0, 0, 3}
