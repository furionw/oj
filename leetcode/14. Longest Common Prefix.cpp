#include <string>
#include <vector>
#include <climits>
#include <iostream>

using namespace std;

class Solution 
{
public:
    string longestCommonPrefix(vector<string> &strs) 
    {
		if (strs.size() == 0)
		{
			return string();
		} else if (strs.size() == 1)
		{
			return strs[0];
		}

    	int length = INT_MAX;

    	for (int  i = 0; i < strs.size()-1; ++ i)
    	{
    		size_t j = 0;
    		while( j<strs[i].size() && j<strs[i+1].size() 
    			&& j<length && strs[i][j] == strs[i+1][j]) 
    		{
    			++ j;
    		}
    		length = length<j? length: j;
    	}

    	return strs[0].substr(0, length);
    }
};

int main()
{
	cout << (int(0)<int(size_t(-1))) << endl;

	return 0;
}