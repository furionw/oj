// Copyright 2016 Qi Wang
// They call this bucket sort. The time complexity is O(N)
// Date: 2016-10-31
class Solution {
 public:
  vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> cnts;
    for (int num : nums)
      ++cnts[num];
    vector<list<int>> cntTable(nums.size() + 1);
    for (auto& cnt : cnts)
      cntTable[cnt.second].push_back(cnt.first);
    vector<int> temp;
    for (auto it = cntTable.rbegin(); it != cntTable.rend(); ++it)
      temp.insert(temp.end(), it->begin(), it->end());
    return vector<int>(temp.begin(), temp.begin() + k);
  }
};
