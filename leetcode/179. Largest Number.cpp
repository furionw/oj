#include <queue>
#include <string>
#include <sstream>

using namespace std;

class Solution
{
public:
	string largestNumber(vector<int> &num)
	{
		vector<string> strs(num.size());
		for (size_t i = 0; i < num.size(); ++i)
		{
			strs[i] = int_to_string(num[i]);
		}
		sort(strs.begin(), strs.end(), [](string a, string b) -> bool
		{
			return (a + b) > (b + a);
		});
		string ret;
		for (const auto& str : strs)
		{
			ret += str;
		}
		return ret[0]=='0'? "0": ret;
	}

private:
	string int_to_string(int num)
	{
		stringstream ss;
		ss << num;
		string str;
		ss >> str;
		return str;
	}
};