// Copyright 2017 Qi Wang
// Date: 2017-10-28
// Case 1: [1, 2, 3]
// Case 2: [1, 5 ,2, 4]
class Solution {
 public:
  bool increasingTriplet(vector<int>& nums) {
    if (nums.size() < 3) return false;
    int smallest = INT_MAX, middle = INT_MAX;
    for (int num : nums) {
      if (num <= smallest) {
        smallest = num;
      } else if (num <= middle) {
        middle = num;
      } else {
        return true;
      }
    }
    return false;
  }
};

// Date: 2017-08-13
class Solution {
 public:
  bool increasingTriplet(vector<int>& nums) {
    // FALSE should be returned here
    if (nums.size() < 3) return false;
    int min1 = INT_MAX, min2 = INT_MAX;
    // return true if min1 < min2 < num;
    for (int num : nums) {
      if (num < min1) {
        min1 = num;
      } else if (min1 < num && num < min2) {
        min2 = num;
      } else if (num > min2) {
        return true;
      }
    }
    return false;
  }
};
 
// case 1: nums = [1, 2, 3]
// case 2: nums = [3, 4, 1, 5]
// case 3: nums = [3, 4, 1, 2, 3]

// Date: 2017-07-30
class Solution {
 public:
  bool increasingTriplet(vector<int>& nums) {
    if (nums.size() < 3) return false;
    int a1 = nums.front(), a2 = INT_MAX, b = INT_MAX;
    for (size_t i = 1; i < nums.size(); ++i) {
      if (nums[i] > a2) {
        return true;
      } else if (a1 < nums[i] && nums[i] < a2) {
        a2 = nums[i];
      } else if (nums[i] < a1) {
        if (a2 == INT_MAX) {
          a1 = nums[i];
        } else if (nums[i] > b) {
          a1 = b;
          a2 = nums[i];
        } else {
          b = nums[i];
        }
      }
    }
    return false;
  }
};

// Date: 2016-11-19
class Solution {
 public:
  bool increasingTriplet(vector<int>& nums) {
    int first = INT_MAX, second = INT_MAX;
    for (int num : nums) {
      if (num > second) {
        return true;
      } else if (num > first) {
        second = min(second, num);
      } else {
        first = min(first, num);
      }
    }
    return false;
  }
};
