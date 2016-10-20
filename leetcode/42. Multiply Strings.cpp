#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution 
{
public:
	string multiply(string a, string b) 
	{
		vector<int> result(a.size()+b.size(), 0);
		string ret;
		
		for (size_t i = 0; i < a.size(); ++ i)
		{
			for (size_t j = 0; j < b.size(); +p+ j)
            {
                result[i+j+1] += ((a[i]-48)*(b[j]-48));
            }
		}
        for (int i=a.size()+b.size()-1; i >= 0; -- i)
        {
            if (i > 0)
            {
                result[i-1] += result[i] / 10; // carry
            }
            ret.insert(ret.begin(), result[i]%10+48);
        }
        ret = ret[0]=='0'? ret.substr(1): ret;

        return (a=="0"||b=="0")? "0": ret;
	}
};
/*
class Solution 
{
public:
	string multiply(string a, string b) 
	{
		string result;
		vector<string> s;

		for (int i = a.size()-1; i >= 0; -- i)
		{
			char carry = 0;
			string item(a.size()-1-i, 0);
			for (int j = b.size()-1; j >= 0; -- j)
			{
				item.push_back( ((a[i]-48)*(b[j]-48)+carry)%10 );
				carry = ((a[i]-48)*(b[j]-48)+carry) / 10;
			}
			if (carry != 0)
			{
				item.push_back( carry );
			}
			s.push_back(item);
		}
		int carry = 0;
		for (size_t j = 0; j < s.back().size(); ++ j)
		{
			int sum = carry;
			for (size_t i = 0; i < s.size(); ++ i)
			{
				if (s[i].size() > j)
				{
					sum += s[i][j];
				}
			}
			result.insert(result.begin(), sum%10+48);
			carry = sum / 10;
		}
		while (carry != 0)
		{
			result.insert(result.begin(), carry%10+48);
			carry /= 10;
		}

		return (a=="0"||b=="0")? "0": result;
	}
};*/

int main()
{
	Solution a;
	a.multiply("98"
		, "9");

	return 0;
}