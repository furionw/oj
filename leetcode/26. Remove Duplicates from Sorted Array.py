class Solution:
  def removeDuplicates(self, nums):
    """
    :type nums: List[int]
    :rtype: int
    """
    if len(nums) == 0:
      return 0
    result = 1
    for i in xrange(1, len(nums)):
      if nums[i] != nums[result]:
        nums[result] = nums[i]
        result = result + 1
    return result
