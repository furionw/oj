// 2025-06-03
class Solution {
 public:
  bool canPartitionGrid(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size();
    vector<uint64_t> nums1, nums2;
    unordered_map<uint64_t, int> map1, map2;
    uint64_t s = 0;
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        s += grid[i][j];
        ++map2[grid[i][j]];
      }
      nums1.push_back(s);
    }

    for (int i = 0; i < m - 1; ++i) {
      uint64_t s1 = nums1[i];
      uint64_t s2 = nums1.back() - s1;
      for (int j = 0; j < n; ++j) {
        ++map1[grid[i][j]];
        --map2[grid[i][j]];
      }
      if (s1 == s2) {
        return true;
      } else if (s1 > s2) {
        uint64_t diff = s1 - s2;
        // horizontal strip
        if (grid[i][0] == diff || grid[i][n - 1] == diff) {
          return true;
        }
        if (i == 0) {
          continue;
        }
        // vertical strip
        if (n == 1) {
          if (grid[0][0] == diff || grid[i][0] == diff) {
            return true;
          } else {
            continue;
          }
        }
        if (map1[diff] > 0) {
          return true;
        }
        // s1 < s2
      } else {
        uint64_t diff = s2 - s1;
        // horizontal strip
        if (grid[i + 1][0] == diff || grid[i + 1][n - 1] == diff) {
          return true;
        }
        if (i + 2 == m) {
          continue;
        }
        // vertical strip
        if (n == 1) {
          if (grid[i + 1][0] == diff || grid[m - 1][n - 1] == diff) {
            return true;
          } else {
            continue;
          }
        }
        if (map2[diff] > 0) {
          return true;
        }
      }
    }

    s = 0;
    map1.clear();
    map2.clear();
    for (int j = 0; j < n; ++j) {
      for (int i = 0; i < m; ++i) {
        s += grid[i][j];
        ++map2[grid[i][j]];
      }
      nums2.push_back(s);
    }
    for (int j = 0; j < n - 1; ++j) {
      uint64_t s1 = nums2[j];
      uint64_t s2 = nums2.back() - s1;
      for (int i = 0; i < m; ++i) {
        ++map1[grid[i][j]];
        --map2[grid[i][j]];
      }
      if (s1 == s2) {
        return true;
      } else if (s1 > s2) {
        uint64_t diff = s1 - s2;
        // vertical strip
        if (grid[0][j] == diff || grid[m - 1][j] == diff) {
          return true;
        }
        if (j == 0) {
          continue;
        }
        // horizontal strip
        if (m == 1) {
          if (grid[0][0] == diff || grid[0][j] == diff) {
            return true;
          } else {
            continue;
          }
        }
        if (map1[diff] > 0) {
          return true;
        }
        // s1 < s2
      } else {
        uint64_t diff = s2 - s1;
        // vertical strip
        if (grid[0][j + 1] == diff || grid[m - 1][j + 1] == diff) {
          return true;
        }
        if (j + 2 == n) {
          continue;
        }
        // horizontal strip
        if (m == 1) {
          if (grid[0][j + 1] == diff || grid[0][n - 1] == diff) {
            return true;
          } else {
            continue;
          }
        }
        if (map2[diff] > 0) {
          return true;
        }
      }
    }

    return false;
  }
};