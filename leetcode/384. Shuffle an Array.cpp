// Copyright 2016 Qi Wang
// Reference: https://en.wikipedia.org/wiki/Fisher%E2%80%93Yates_shuffle
// Date: 2016-10-10
class Solution {
 public:
  Solution(vector<int> nums) : originalNums_(nums) {}
    
  /** Resets the array to its original configuration and return it. */
  vector<int> reset() {
    return originalNums_;
  }
    
  /** Returns a random shuffling of the array. */
  vector<int> shuffle() {
    vector<int> res = originalNums_;
    for (int i = res.size() - 1; i >= 1; --i)
      swap(res[i], res[rand() % (i + 1)]);  //
    return res;
  }

 private:
  vector<int> originalNums_;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * vector<int> param_1 = obj.reset();
 * vector<int> param_2 = obj.shuffle();
 */
