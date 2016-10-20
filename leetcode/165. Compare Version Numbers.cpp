class Solution 
{
public:
	int compareVersion(string version1, string version2) 
	{
		while (version1 != "" || version2 != "")
		{
			size_t dot1 = version1.find('.'), dot2 = version2.find('.');
			int level1 = string_to_int(version1.substr(0, dot1));
			int level2 = string_to_int(version2.substr(0, dot2));
			version1 = dot1 != string::npos ? version1.substr(dot1 + 1) : "";
			version2 = dot2 != string::npos ? version2.substr(dot2 + 1) : "";
			if (level1 != level2)
			{
				return level1<level2 ? -1 : 1;
			}
		}
		return 0;
	}

private:
	inline int string_to_int(const string& str)
	{
		if (str == "")
		{
			return 0;
		}
		int ret;
		stringstream ss(str);
		ss >> ret;
		return ret;
	}
};