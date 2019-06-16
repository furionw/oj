# Copyright 2019 Qi Wang
# Date: 2019-06-16
# Refer to: https://leetcode.com/problems/duplicate-zeros/discuss/312727/JavaC%2B%2B-Space-O(1)
class Solution:
    def duplicateZeros(self, arr: List[int]) -> None:
        arr[:] = [x for a in arr for x in ([a] if a else [0, 0])][: len(arr)]

# Date: 2019-06-16
class Solution:
    def duplicateZeros(self, arr: List[int]) -> None:
        result = []
        for num in arr:
            if num == 0:
                result.extend([0, 0])
            else:
                result.append(num)
            if len(result) >= len(arr):
                break
        # Learn from https://leetcode.com/problems/duplicate-zeros/discuss/312727/JavaC%2B%2B-Space-O(1)
        arr[:] = result[0: len(arr)]
