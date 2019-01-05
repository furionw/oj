# Copyright 2019 Qi Wang
# Date: 2019-01-05
import functools

class Solution:
    def numJewelsInStones(self, J, S):
        """
        :type J: str
        :type S: str
        :rtype: int
        """
        s = set(J)
        return functools.reduce(lambda acc, cur: acc + (1 if cur in s else 0), S, 0)
