# Copyright 2019 Qi Wang
# Date: 2019-01-26
class Solution:
    def sortedSquares(self, A):
        """
        :type A: List[int]
        :rtype: List[int]
        """
        res = list(map(lambda x: x * x, A))
        res.sort()
        return res
