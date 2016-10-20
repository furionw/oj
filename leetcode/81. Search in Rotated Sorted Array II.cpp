class Solution 
{
public:
    bool search(int A[], int n, int target) 
    {
    	return find(A, 0, n-1, target);
    }
private:
	bool find(int a[], int l, int r, int target)
	{
		if (l > r)
		{
			return false;
		} else if (l == r)
		{
			return a[l] == target;
		}

		if (a[l] < a[r])
		{
			while (l < r)
			{
				int mid = (l+r) >> 1;
				if (a[mid] < target)
				{
					l = mid + 1;
				} else if (a[mid] > target)
				{
					r = mid - 1;
				} else 
				{
					return true;
				}
			}
		}

		return find(a, l, (l+r)>>1, target) || find(a, ((l+r)>>1)+1, r, target);
	}
};