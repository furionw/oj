#include <cmath>
#include <iostream>

using namespace std;

class Solution 
{
public:
	int divide(int dividend, int divisor) 
	{
		bool negative = (dividend<0&&divisor>0) || (dividend>0&&divisor<0);
		// 先转型为long long, 否则abs(-2147483648)会溢出，因为int的上界为2147483647
		long long c = dividend, d = divisor; // 在LeetCode上 long long a = abs(long long(dividend)) 编译错误
		long long a = abs(c), b = abs(d);
		int quotient = 0;


		while (a >= b)
		{
			long long sum = b;
			int cnt = 1;
			while (sum + sum <= a)
			{
				sum += sum;
				cnt += cnt;
			}
			a -= sum;
			quotient += cnt;
		}


		return negative? -quotient: quotient;
	}
};

int main()
{
	Solution a;                   
	int dividend = -1010369383;
	int divisor = -2147483648;
	cout << a.divide(dividend, divisor);

	return 0;
}