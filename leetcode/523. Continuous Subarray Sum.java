// Date: 2020-05-30
// Refer to: https://leetcode.com/problems/continuous-subarray-sum/discuss/99499/Java-O(n)-time-O(k)-space
class Solution {
  public boolean checkSubarraySum(int[] nums, int k) {
    if (nums == null) {
      return false;
    }
    Map<Integer, Integer> remainderToIdxMap = new HashMap<Integer, Integer>();
    remainderToIdxMap.put(0, -1);
    for (int i = 0, remainder = 0; i < nums.length; ++i) {
      remainder += nums[i];
      if (k != 0) {
        remainder %= k;
      }
      if (remainderToIdxMap.containsKey(remainder)) {
        if (i - remainderToIdxMap.get(remainder) > 1) {
          return true;
        }
      } else {
        remainderToIdxMap.put(remainder, i);
      }
    }
    return false;
  }
}