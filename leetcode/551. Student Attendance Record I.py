# Copyright 2018 Qi Wang
# Date: 2018-12-15
class Solution:
    def checkRecord(self, s):
        """
        :type s: str
        :rtype: bool
        """
        absent_cnt = 0
        late_cnt = 0
        for c in s:
            if c == 'A':
                absent_cnt += 1
                if absent_cnt == 2:
                    return False
                late_cnt = 0
            elif c == 'L':
                late_cnt += 1
                if late_cnt == 3:
                    return False
            else:
                late_cnt = 0
        return True
