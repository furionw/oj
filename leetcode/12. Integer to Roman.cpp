#include <cstring>
#include <string>
#include <iostream>

using namespace std;

class Solution 
{
public:
    string intToRoman(int num) 
    {
		// Ã»ÓÐ450, ºÍ45
    	int digit[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    	string str[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    	string ret;

    	for (int i = 0; i < sizeof(digit)/sizeof(int); ++ i)
    	{
    		while (num >= digit[i])
    		{
    			num -= digit[i];
    			ret += str[i];
    		}
    	}

    	return ret;
    }
};

int main()
{
	Solution a;
	cout << a.intToRoman(1);

	return 0;
}