# Copyright 2019 Qi Wang
# Date: 2019-06-02
class Solution:
    def gcdOfStrings(self, str1: str, str2: str) -> str:
        if len(str1) < len(str2):
            return self.gcdOfStrings(str2, str1)
        assert len(str1) >= len(str2)
        for sz in range(len(str2), 0, -1):
            divisor = str2[0: sz]
            if self.divides(divisor, str1) and self.divides(divisor, str2):
                return divisor
        return ""
        
    def divides(self, divisor: str, dividend: str) -> bool:
        if len(dividend) % len(divisor) != 0:
            return False
        for i in range(0, len(dividend), len(divisor)):
            if dividend[i: i + len(divisor)] != divisor:
                return False
        return True
