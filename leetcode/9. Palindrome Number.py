class Solution(object):
    def isPalindrome(self, x):
        if x < 0:
            return False

        base = 1
        while x >= base * 10:
            base *= 10
        while x > 0:
            if int(x / base) != x % 10:
                return False
            # calculate x first, then base
            x = int((x % base) / 10)
            base /= 100

        return True

print(Solution().isPalindrome(11111))
