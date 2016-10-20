class Solution(object):
	def lengthOfLongestSubstring(self, s):
		substr = ''
		length = 0
		i = 0
		for i in range(0, len(s)):
			if substr.find(s[i]) == -1:
				substr = substr + s[i]
				length = max(length, len(substr))
			else:
				substr = substr[substr.find(s[i])+1:] + s[i]
		return length
