class Solution 
{
public:
    bool isPalindrome(int x) 
    {
        if (x < 0)
        {
        	return false;
        }

        int rightmost = 1;
        for (int copy = x/10; copy>0; copy/=10, rightmost*=10) {}
        while (x != 0)
        {
        	if (x/rightmost != x%10)
        	{
        		return false;
        	} else
        	{
        		x = (x%rightmost)/10; // cut off the rightmost and leftmost digits
           		rightmost /= 100;
        	}
        }    		

        return true;
    }
};