#include <string>
#include <vector>

using namespace std;

class Solution 
{
public:
    string convert(string s, int nRows) 
    {
		if (nRows == 1)
		{
			return s;
		}

    	string ret;
		vector<string> rows(nRows);
		int interval = 2*nRows-2;

		for (size_t i = 0; i < s.size(); ++ i)
		{
			if (i % interval < nRows)
			{
				rows[i%interval] += s[i];
			} else
			{
				rows[nRows-1-(i%interval-nRows+1)] += s[i];
			}
		}
		for (size_t i = 0; i < nRows; ++ i)
		{
			ret += rows[i];
		}

		return ret;
    }
};