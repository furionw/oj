class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    	int sz = nums1.size() + nums2.size();
		if (sz % 2 == 0)
    		return (find_kth(nums1.data(), nums1.size(), nums2.data(), nums2.size(), sz / 2)
    			+ find_kth(nums1.data(), nums1.size(), nums2.data(), nums2.size(), sz / 2 + 1)) / 2;
		else 
			return find_kth(nums1.data(), nums1.size(), nums2.data(), 
				nums2.size(), sz / 2 + 1);
    }

private:
	double find_kth(const int *a, size_t m, const int *b, size_t n, size_t k) {
		if (m > n)
			return find_kth(b, n, a, m, k);
		else if (m == 0)
			return b[k-1];
		else if (k == 1)
			return min(a[0], b[0]);

		size_t pa = min(m, k/2);
		size_t pb = k - pa; // find out the evaluation order of commma operator, plz
		if (a[pa-1] < b[pb-1])
			return find_kth(a+pa, m-pa, b, n, k-pa);
		else if (a[pa-1] > b[pb-1])
			return find_kth(a, m, b+pb, n-pb, k-pb);
		else
			return a[pa-1];
	}
};