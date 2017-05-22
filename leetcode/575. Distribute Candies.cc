// Copyright 2017 Qi Wang
// Date: 2017-05-22
class Solution {
 public:
  int distributeCandies(vector<int>& candies) {
    unordered_set<int> cnts;
    for (int candy : candies)
      cnts.insert(candy);
    return min(candies.size() >> 1, cnts.size());
  }
};
