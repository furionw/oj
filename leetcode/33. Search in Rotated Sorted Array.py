# Copyright 2019 Qi Wang
# Date: 2019-06-05
class Solution:
    def search(self, nums: List[int], target: int) -> int:
        l = 0
        r = len(nums) - 1
        while l <= r:
            mid = int((l + r) / 2)
            # print(l, r, mid)
            if target == nums[mid]:
                return mid
            elif target > nums[mid]:
                # nums[mid] > nums[r] meaning the maximal value is on the right
                # The 2nd condition, i.e. (nums[mid] <= nums[r] and target <= nums[r]), meaning
                # the right part strictly increases and target is less than its maxiaml value.
                if nums[mid] > nums[r] or target <= nums[r]:
                    l = mid + 1
                else:
                    r = mid - 1
            else:  # i.e. target < nums[mid]
                if nums[l] > nums[mid] or target >= nums[l]:
                    r = mid - 1
                else:
                    l = mid + 1
        return -1
