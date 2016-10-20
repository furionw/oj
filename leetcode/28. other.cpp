#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

        if (dividend == 0 || divisor == 0)
            return 0;

        int nega = 0;
        if ((dividend>0&&divisor<0) || (dividend<0&&divisor>0))
            nega = 1;
        
        long long c = dividend;    //先用两个long long来存一下，不然下面abs(-2147483648)会溢出，因为正数int只能到2147483647
        long long d = divisor;
        long long a = abs(c);
        long long b = abs(d);

        if (b > a)
            return 0;

        long long sum = 0;
        int count = 0;
        int final = 0;
        while (a >= b)
        {
            count = 1;                //a >= b保证了最少有一个count
            sum = b;
            while (sum + sum <= a){    //!!
                sum += sum;
                count += count;
            }
            a -= sum;
            final += count;
        }

        if (nega)
            final = 0 - final;

        return final;
    }
};

int main()
{
    int dividend = -100;
    int divisor = -2147483648;
    Solution s;
    cout<<s.divide(dividend, divisor)<<endl;
    return 0;
}