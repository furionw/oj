#include <vector>
#include <iostream>
#include <map>
#include <string>

using namespace std;

class Solution 
{
public:
	vector<int> findSubstring(string S, vector<string> &L) 
	{
		if( L.empty() == true )
		{
			return vector<int>();
		}
		vector<int> ret;
		map<string, int> cnt;
		int word_size = L[0].size();
		for (auto it = L.begin(); it != L.end(); ++ it)
		{
			++ cnt[*it];
		}    

		for (int begin = 0; begin <= int(S.size())-int(L.size()*word_size); ++ begin)
		{
			map<string, int> tmp;
			size_t i = 0;
			for ( ; i < L.size(); ++ i)
			{
				if (++ tmp[S.substr(begin+i*word_size, word_size)] > cnt[S.substr(begin+i*word_size, word_size)] )
				{
					break;
				}
			}
			if (i == L.size())
			{
				ret.push_back(begin);
			}
		}

		return ret;
	}
};

int main()
{
	Solution a;
	vector<string> l;
	l.push_back("foo");
	l.push_back("bar");
	auto ans = a.findSubstring("barfoothefoobarman", l);

	return 0;
}