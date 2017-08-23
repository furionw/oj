// Copyright 2017 Qi Wang
// Date: 2017-08-17
class Solution {
 public:
  int leastBricks(vector<vector<int>>& wall) {
    unordered_map<int, int> offset_to_cnt_map;
    for (const auto& row : wall) {
      for (int i = 0, acc = 0; i + 1< row.size(); ++i) {
        ++offset_to_cnt_map[acc += row[i]];
      }
    }
    int result = 0;
    for (const auto& offset_cnt_pair : offset_to_cnt_map) {
      result = max(result, offset_cnt_pair.second);
    }
    return wall.size() - result;
  }
};

// Date: 2017-08-04
class Solution {
 public:
  int leastBricks(vector<vector<int>>& wall) {
    unordered_map<int, int> offset_to_cnt_map;
    for (const auto& vt : wall) {
      int acc = 0;
      for (int i = 0; i < vt.size() - 1; ++i) {
        ++offset_to_cnt_map[acc += vt[i]];
      }
    }
    int most_frequent_offset = 0;
    for (const auto& p : offset_to_cnt_map) {
      most_frequent_offset = max(most_frequent_offset, p.second);
    }
    return wall.size() - most_frequent_offset;
  }
};

// Date: 2017-05-02
class Solution {
 public:
  int leastBricks(vector<vector<int>>& wall) {
    unordered_map<int, int> cnts;
    for (const auto& row : wall) {
      int acc = 0;
      for (size_t i = 0; i < row.size() - 1; ++i)
        ++cnts[acc += row[i]];
    }
    int max_edge = 0;
    for (const auto& p : cnts) max_edge = max(max_edge, p.second);
    return wall.size() - max_edge;
  }
};
