class Solution(object):
	def isAnagram(self, s, t):
		if len(s) == len(t):
			return self.statistic(s) == self.statistic(t)
		else:
			return False
	
	def statistic(self, s):
		ret = {}
		for c in s:
			if ret.get(c) != None:
				ret[c] += 1
			else:
				ret[c] = 1
		return ret
		
Solution().isAnagram("hi", "ih");
