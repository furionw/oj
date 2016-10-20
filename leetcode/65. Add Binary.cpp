#include <string>

using namespace std;

class Solution 
{
public:
    string addBinary(string a, string b) 
    {
    	int i, j, carry=0;
    	string ret;    	
    	
    	for (i=a.size()-1, j=b.size()-1; i>=0 && j>=0; --i, --j)
    	{
    		ret.insert(ret.begin(), '0'+(a[i]+b[j]+carry-'0'-'0')%2);
    		carry = (a[i]+b[j]+carry-'0'-'0') / 2;
    	}
    	for ( ; i >= 0; -- i)
    	{
			ret.insert(ret.begin(), '0'+(a[i]+carry-'0')%2);
    		carry = (a[i]+carry-'0') / 2;
    	}
    	for ( ; j >= 0; -- j)
    	{
    		ret.insert(ret.begin(), '0'+(b[j]+carry-'0')%2);
    		carry = (b[j]+carry-'0') / 2;
    	}
    	ret.insert(0, carry!=0? "1": "");

    	return ret;
    }
};