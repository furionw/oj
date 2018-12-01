class Solution:
    def minIncrementForUnique(self, A):
        """
        :type A: List[int]
        :rtype: int
        """
        if not A:
            return 0
        A.sort()
        result = 0
        for i in range(1, len(A)):
            if A[i] <= A[i - 1]:
                result += A[i - 1] - A[i] + 1
                A[i] = A[i - 1] + 1
        return result
