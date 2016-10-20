class Solution 
{
public:
    int search(int A[], int n, int target) 
    {
    	return find(A, 0, n-1, target);
    }
private:
	int find(int a[], int l, int r, int target)
	{
		if (l > r)
		{
			return -1;
		}

		int index = -1, mid = (l+r)>>1;

		if (a[l] < a[r])
		{
			while (l <= r)
			{
				mid = (l+r) >> 1;
				if (a[mid] == target)
				{
					index = mid;
					break;
				} else if (a[mid] < target)
				{
					l = mid + 1;
				} else
				{
					r = mid - 1;
				}
			}
		} else
		{
			index = find(a, l, mid, target);
			index = index!=-1? index: find(a, mid+1, r, target);
		}

		return index;
	}
};