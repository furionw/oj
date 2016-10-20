#include <string>
#include <vector>

using namespace std;

class Solution 
{
public:
	string countAndSay(int n) 
	{
		string num("1"), next_num;
		
		for (int i = 1; i < n; ++ i)
		{
			int cnt = '0', last = num[0];
			next_num.clear();
			for (size_t j = 0; j < num.size(); ++ j)
			{
				if (num[j] == last)
				{
					++ cnt;
				} else
				{
					next_num += cnt;
					next_num += last;
					cnt = '1';
					last = num[j];
				}
			}
			next_num += cnt;
			next_num += last;
			num = next_num;
		}

		return num;
	}
};

int main()
{
	Solution a;
	a.countAndSay(2);

	return 0;
}