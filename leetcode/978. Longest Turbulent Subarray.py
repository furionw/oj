# Copyright 2019 Qi Wang
# Date: 2019-01-26
class Solution:
    def maxTurbulenceSize(self, A):
        """
        :type A: List[int]
        :rtype: int
        """
        sz = len(A)
        if (sz == 0):
            return 0
        less_than_prev = [1] * sz
        larger_than_prev = [1] * sz
        for i in range(1, sz):
            if A[i] > A[i - 1]:
                larger_than_prev[i] = less_than_prev[i - 1] + 1
            elif A[i] < A[i - 1]:
                less_than_prev[i] = larger_than_prev[i - 1] + 1
        return max(max(less_than_prev), max(larger_than_prev))
