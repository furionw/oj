// Copyright 2020 Qi Wang
// Date: 2020-05-24
class Solution {
  public int[] productExceptSelf(int[] nums) {
    int[] result = new int[nums.length];
    for (int i = 0, acc = 1; i < nums.length; ++i) {
      result[i] = acc;
      acc *= nums[i];
    }
    for (int i = nums.length - 1, acc = 1; i >= 0; --i) {
      result[i] *= acc;
      acc *= nums[i];
    }
    return result;
  }
}
