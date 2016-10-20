#include <cstring>
#include <climits>

class Solution 
{
public:
	int atoi(const char *str) 
	{
		int ret = 0;
		bool negative = false;

		for ( ; strlen(str)>0 && *str==' '; ++ str) {}
		if (strlen(str) == 0)
		{
			return 0;
		} else if (*str == '+' || *str=='-')
		{
			negative = *str=='-';
			++ str;
		}
		bool accpect_no_more_digit = false;
		bool accpect_no_large_digit = false;
		for ( ; strlen(str)>0 && *str<='9' && *str>='0'; ++ str)
		{
			if ( accpect_no_more_digit == true )
			{
				return ret>0? INT_MAX: INT_MIN;
			} else if (accpect_no_large_digit == true)
			{
				if ( ret>0 && *str<='7' )
				{
					ret = 10*ret + *str - '0';
				} else if ( ret<0 && *str<='8' )
				{
					ret = 10*ret - (*str - '0');
				} else
				{
					return ret>0? INT_MAX: INT_MIN;					
				}
			} else if (negative == false)
			{
				ret = 10*ret + *str - '0';
			} else 
			{
				ret = 10*ret - (*str - '0');
			}
			accpect_no_more_digit = ret>INT_MAX/10 || ret<INT_MIN/10;
			accpect_no_large_digit = ret==INT_MAX/10 || ret==INT_MIN/10;
		}

		return ret;
	}
};

#include <iostream>
using namespace std;
/*
int main()
{
	cout << sizeof(int) << endl;
	cout << long long(2147483648) << endl;
	unsigned int cover = 0x70000000;
	long long ans = 9147483641;
	// 0111
	cout << ans << endl;
	cout << int(ans) << endl;


	return 0;
}*/