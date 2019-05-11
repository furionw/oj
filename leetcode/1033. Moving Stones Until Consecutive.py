# Copyright 2019 Qi Wang
# Date: 2019-05-12
class Solution:
    def numMovesStones(self, a: int, b: int, c: int) -> List[int]:
        if a > b:
            return self.numMovesStones(b, a, c)
        if a > c:
            return self.numMovesStones(c, b, a)
        if b > c:
            return self.numMovesStones(a, c, b)
        # Now a < b < c
        min_move = 2
        if a + 2 == c:
            min_move = 0
        elif a + 1 == b or b + 1 == c or a + 2 == b or b + 2 == c:
            min_move = 1
        return [min_move, c - a - 2]
