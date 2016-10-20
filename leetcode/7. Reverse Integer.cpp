#include <iostream>

using namespace std;

// 1463847419 -> 9147483641
// 2147483647
// -2147483648

class Solution 
{
public:
	int reverse(int x) 
	{
		if( overflow(x) == true)
		{
			return -1;
		}

		int ret = 0;
		
		while (x!=0)
		{
			ret = 10*ret + x%10;
			x /= 10;
		}

		return ret;
	}
private:
	bool overflow(int x)
	{
		if (x / 1000000000 == 0)
		{
			return false;
		} else if (x == INT_MIN)
		{
			return true;
		} 
		x = abs(x);
		//     7463847412 ->  2147483647
		// or -8463847412 -> -2147483648
		for (int cmp = 463847412; cmp != 0; cmp/=10, x/=10)
		{
			if ( x%10 > cmp%10 )
			{
				return true;
			} else if (x%10 < cmp%10)
			{
				return false;
			}
		}
		
		return false;
	}
};

int main()
{
	Solution a;
	cout << a.reverse(-123);
  return 0;
}
