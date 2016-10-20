class Solution 
{
public:
    vector<vector<string>> partition(string s) 
    {
    	vector<string> cur;
    	recurse(s, cur);
    	return ret;
    }

private:
	void recurse(const string& s, vector<string>& cur)
	{
		if (s.size() == 0)
		{
			ret.push_back( cur );
		}
		cout << ret.size() << endl;
		for (size_t len = 1; len <= s.size(); ++ len)
		{
			if (is_palindrome(s.substr(0, len)) == true)
			{
				cur.push_back( s.substr(0, len) );
				recurse(s.substr(len), cur);
				cur.pop_back();
			}
		}
	}

	bool is_palindrome(const string& s)
	{
		string str(1, '*');
		for (size_t i = 0; i < s.size(); ++ i)
		{
			str.insert(str.end(), s[i]);
			str.insert(str.end(), '*');
		}
		int mid = str.size() / 2;
		for (int i = 0; mid-i >= 0; ++ i)
		{
			if (str[mid-i] != str[mid+i])
			{
				return false;
			}
		}
		return true;
	}

	vector<vector<string>> ret;
};