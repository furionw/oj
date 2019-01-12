# Copyright 2019 Qi Wang
# Date: 2019-01-12
class Solution:
    def powerfulIntegers(self, x, y, bound):
        """
        :type x: int
        :type y: int
        :type bound: int
        :rtype: List[int]
        """
        if x == 0 and y == 0:
            return [0]
        elif x == 0 or y == 0:
            return self.helper(x + y, bound)
        l1 = self.helper(x, bound)
        l2 = self.helper(y, bound)
        s = set()
        for num1 in l1:
            for num2 in l2:
                if num1 + num2 <= bound:
                    s.add(num1 + num2)
                else:
                    break
        return list(s)
    
    def helper(self, x, bound):
        if x == 1:
            return [1] if bound >= 1 else []
        res = []
        i = 0
        while pow(x, i) <= bound:
            res.append(pow(x, i))
            i += 1
        return res
