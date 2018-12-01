class Solution:
    def moveZeroes(self, nums):
        """
        :type nums: List[int]
        :rtype: void Do not return anything, modify nums in-place instead.
        """
        non_zero_idx = 0
        for num in nums:
            if num != 0:
                nums[non_zero_idx] = num
                non_zero_idx = non_zero_idx + 1
        zero_idx = non_zero_idx
        while zero_idx < len(nums):
            nums[zero_idx] = 0
            zero_idx = zero_idx + 1