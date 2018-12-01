class Solution:
    def flipAndInvertImage(self, A):
        """
        :type A: List[List[int]]
        :rtype: List[List[int]]
        """
        for i in range(0, len(A)):
            A[i].reverse()
            for j in range(0, len(A[i])):
                A[i][j] = 1 - A[i][j]
        return A

import unittest

class TestSolution(unittest.TestCase):
    def test_foo(self):
        s = Solution()
        self.assertEqual(s.flipAndInvertImage([[1, 0, 1], [0, 0, 0]]),
                         [[0, 1, 0], [1, 1, 1]])
        self.assertEqual(s.flipAndInvertImage([[1,1,0], [1,0,1], [0,0,0]]),
                         [[1,0,0], [0,1,0], [1,1,1]])
    

if __name__ == "__main__":
    unittest.main()
