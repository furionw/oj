// Copyright 2017 Qi Wang
// Date: 2017-10-11
class Solution {
 public:
  vector<vector<int>> threeSum(vector<int> &numbers) {
    sort(numbers.begin(), numbers.end());
    vector<vector<int>> result;
    for (int i = 0; i < numbers.size();) {
      for (int j = i + 1, k = numbers.size() - 1; j < k;) {
        if (numbers[i] + numbers[j] + numbers[k] == 0) {
          result.push_back(vector<int> {numbers[i], numbers[j], numbers[k]});
          Advance(numbers, &j);
          --k;
        } else if (numbers[i] + numbers[j] + numbers[k] < 0) {
          Advance(numbers, &j);
        } else {
          --k;
        }
      }
      Advance(numbers, &i);
    }
    return result;
  }
 
 private:
  void Advance(const vector<int>& nums, int *idx) const {
    for (++*idx; *idx < nums.size() && nums[*idx] == nums[*idx - 1];
         ++*idx) {}
  }
};
