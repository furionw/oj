class Solution(object):
	def findMedianSortedArrays(self, nums1, nums2):
		sz = len(nums1) + len(nums2)
		if sz % 2 == 1:
			return self.find_kth(nums1, nums2, sz / 2 + 1)
		else:
			return (self.find_kth(nums1, nums2, sz / 2) 
				+ self.find_kth(nums1, nums2, sz / 2 + 1)) / 2.0
	
	def find_kth(self, a, b, k):
		k = int(k)
		m = len(a)
		n = len(b)
		if m > n:
			return self.find_kth(b, a, k)
		elif m == 0:
			return b[k-1]
		elif k == 1:
			return min(a[0], b[0])

		pa = int(min(m, k/2))
		pb = k - pa
		if a[pa-1] < b[pb-1]:
			return self.find_kth(a[pa:], b, k-pa)
		elif a[pa-1] > b[pb-1]:
			return self.find_kth(a, b[pb:], k-pb)
		else:
			return a[pa-1]

print(Solution().findMedianSortedArrays([2], []))
