class Solution(object):
    def convert(self, s, numRows):
        if numRows == 1:
            return s
        res = str()
        offset = 2 * numRows - 2
        for i in range(0, numRows):
            j = 0
            while True:
                if i == 0 or i == numRows - 1:
                    idx = j * offset + i
                else:
                    idx = int((j + 1) / 2) * offset + (i if j % 2 == 0 else -i)
                if idx < len(s):
                    res += s[idx]
                else:
                    break;
                j = j + 1
        return res

print(Solution().convert("ABCDEF", 3))
