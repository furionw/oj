class Solution 
{
public:
    int sqrt(int x) 
	{
        long long l=1, r=x, mid=x;

        while (l <= r)
        {
        	mid = (l+r) >> 1;
        	if (mid*mid == x)
        	{
        		return mid;
        	} else if (mid*mid < x)
        	{
        		l = mid + 1;
        	} else
        	{
        		r = mid - 1;
        	}
        }

        return mid*mid>x? mid-1:mid;
    }
};