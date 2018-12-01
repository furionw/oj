from functools import reduce

class Solution:
    def uniqueMorseRepresentations(self, words):
        """
        :type words: List[str]
        :rtype: int
        """
        c_to_str = [".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."]
        result_set = set()
        for word in words:
            result_set.add(reduce((lambda acc, cur: acc + c_to_str[ord(cur) - ord('a')]), word, ''))
        return len(result_set)

import unittest

class TestSolution(unittest.TestCase):
    def test_foo(self):
        s = Solution()
        self.assertEqual(s.uniqueMorseRepresentations(["gin", "zen", "gig", "msg"]), 2)
    

if __name__ == "__main__":
    unittest.main()
