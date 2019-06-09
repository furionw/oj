# Copyright 2019 Qi Wang
# Date: 2019-06-08
# Refer to: https://leetcode.com/problems/flip-columns-for-maximum-number-of-equal-rows/discuss/303752/Python-1-Line
class Solution:
    def maxEqualRowsAfterFlips(self, A: List[List[int]]) -> int:
        return max(collections.Counter(tuple(elem ^ row[0] for elem in row) for row in A).values())

# Date: 2019-06-08
class Solution:
    def maxEqualRowsAfterFlips(self, matrix: List[List[int]]) -> int:
        candidate_rows = [i for i in range(len(matrix))]
        self.maxEqualRowsAfterFlipsCore(matrix, 1, candidate_rows)
        self.flip(matrix, 0)
        self.maxEqualRowsAfterFlipsCore(matrix, 1, candidate_rows)
        return self.result

    def maxEqualRowsAfterFlipsCore(self, matrix, j, candidate_rows):
        if len(candidate_rows) <= self.result:
            return
        if len(matrix[0]) == j:
            self.result = max(self.result, len(candidate_rows))
            return
        # Not flip
        next_candidate_rows = self.get_next_candidate_rows(matrix, j, candidate_rows)
        self.maxEqualRowsAfterFlipsCore(matrix, j + 1, next_candidate_rows)
        # Filp
        self.flip(matrix, j)
        next_candidate_rows = self.get_next_candidate_rows(matrix, j, candidate_rows)
        self.maxEqualRowsAfterFlipsCore(matrix, j + 1, next_candidate_rows)
        self.flip(matrix, j)
    
    def get_next_candidate_rows(self, matrix, j, candidate_rows):
        return list(filter(lambda i: matrix[i][j] == matrix[i][j - 1], candidate_rows))

    def flip(self, matrix, j):
        for i in range(len(matrix)):
            matrix[i][j] = 1 - matrix[i][j]

    result = 0
