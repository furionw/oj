#include <string>
#include <iostream>

using namespace std;

void reverseWords(string &s) 
{
	string s2;
	bool first = true;

	for (size_t i = 0; i < s.size(); ++ i)
	{
		int begin, end;
		for ( ; i < s.size() && s[i] == ' '; ++ i ) {}
		begin = i;
		for ( ; i < s.size() && s[i] != ' '; ++ i) {}
		end = i;
		if (begin == s.size())
		{
			break;
		}
		if (first == true)
		{
			s2.insert(0, s.substr(begin, end-begin));
			first =  false;
		} else
		{
			s2.insert(0, " ");
			s2.insert(0, s.substr(begin, end-begin));
		}
	}

	s = s2;
}

int main()
{
	string s1 = "  the sky are so  blue ";

	reverseWords( s1 );

	return 0;
}