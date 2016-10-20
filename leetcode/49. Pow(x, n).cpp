#include <iostream>

using namespace std;

class Solution 
{
public:
    double pow(double x, int n) 
    {
    	if (n == 0)
    	{
    		return 1;
    	}

    	bool negative = n<0;
		double ret=x;
    	long long tmp = 1, cnt = 0;
		long long nn = n;
    	while (tmp*2 <= abs(nn))
    	{
    		tmp *= 2;
    		++ cnt;
    	}
    	while (cnt --)
    	{
    		ret *= ret;
    	}

    	return negative? 1/(ret*pow(x, abs(n)-tmp)): ret*pow(x, abs(n)-tmp);
    }
};

int main()
{
	Solution a;
	a.pow( 1, -2147483648 );

	return 0;
}