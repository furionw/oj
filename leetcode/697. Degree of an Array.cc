// Copyright 2017 Qi Wang
// Date: 2017-10-17
class Solution {
 public:
  int findShortestSubArray(vector<int>& nums) {
    Record records[50000];
    for (int i = 0; i < nums.size(); ++i) {
      if (++records[nums[i]].freq == 1) {
        records[nums[i]].start = records[nums[i]].end = i;
      } else {
        records[nums[i]].end = i;
      }
    }
    int max_freq = 0, result = 0;
    for (int i = 0; i < 50000; ++i) {
      if (records[i].freq > max_freq) {
        max_freq = records[i].freq;
        result = records[i].end - records[i].start + 1;
      } else if (records[i].freq == max_freq) {
        result = min(result, records[i].end - records[i].start + 1);
      }
    }
    return result;
  }
 
 private:
  struct Record {
    int freq = 0;
    int start = -1;
    int end = -1;
  };
};
