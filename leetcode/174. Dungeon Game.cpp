// Copyright 2016 Stephen Wong

// Date: 2016-09-29
class Solution {
 public:
  int calculateMinimumHP(vector<vector<int>>& dungeon) {
    
  }
};

// TLE
// Date: 2016-09-29
class Solution {
 public:
  int calculateMinimumHP(vector<vector<int>>& dungeon) {
    int res = INT_MAX;
    calculateMinimumHP(dungeon, 0, 0, 1, 1, res);
    return res;
  }

 private:
  void calculateMinimumHP(const vector<vector<int>>& dungeon, int i, int j,
      int preCost, int maxCost, int& res) {
    int curCost = preCost - dungeon[i][j];
    // prune
    if (curCost >= res) return;
    maxCost = max(maxCost, curCost);
    if (i + 1== dungeon.size() && j + 1 == dungeon[0].size()) {
      // We get the princess
      res = min(res, maxCost);
    } else {
      if (i + 1 < dungeon.size())
        calculateMinimumHP(dungeon, i + 1, j, curCost, maxCost, res);
      if (j + 1 < dungeon[0].size())
        calculateMinimumHP(dungeon, i, j + 1, curCost, maxCost, res);
    }
  }
};
