// Copyright 2017 Qi Wang
// Date: 2017-04-16
class Solution {
 public:
  int myAtoi(string str) {
    bool positive = true;
    bool find_sign = false;
    bool find_digit = false;
    int result = 0;
    for (char c : str) {
      if (c == '+') {
        // duplicate sign
        if (find_sign) {
          return 0;
        } else {
          find_sign = true;
        }
      } else if (c == '-') {
        if (find_sign) {
          return 0;
        } else {
          find_sign = true;
          positive = false;
        }
      } else if ('0' <= c && c <= '9') {
        find_digit = true;
        if (positive && (result > INT_MAX / 10
            || (result == INT_MAX / 10 && c - '0' >= 7))) {
          return INT_MAX;
        } else if (!positive && (result > INT_MAX / 10
            || (result == INT_MAX / 10 && c - '0' >= 8))) {
          return INT_MIN;
        }
        result = result * 10 + c - '0';
      } else if (c == ' ') {
        // error case
        if (find_sign || find_digit) break;
      } else {
        break;
      }
    }
    return positive ? result : -result;
  }
};

// 
class Solution {
 public:
  int myAtoi(string str) {
    int64_t res = 0;
    bool digit_begin = false;
    bool digit_end = false;
    bool positive = true;

    // Note that the if-conditions in the first level are all about characters
    // Thus we could use "else break" in the end
    for (size_t i = 0; i < str.size(); ++ i)
      // We have to use braces here to avoid the dangling else for '+' and '-'
      if (str[i] == ' ') {
        if (digit_begin) break;  // parse end
      } else if (str[i] == '+' || str[i] == '-')
        if (! digit_begin) {
          positive = (str[i]=='+')? positive: !positive;
          digit_begin = true;
        } else
          break;
      else if (str[i] >= '0' && str[i] <= '9') {
        digit_begin = true;
        res = 10 * res + (str[i] - '0');
        if (res > INT_MAX)  // That is, abs(res) >= INT_MIN
          return positive? INT_MAX: INT_MIN;
      } else
        break;  // parse end

    return positive? res: -res;
  }
};

//
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