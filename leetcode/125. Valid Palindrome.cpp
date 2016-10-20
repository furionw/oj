class Solution 
{
public:
    bool isPalindrome(string s) 
    {
    	string str(1, '/');
    	for (size_t i = 0; i < s.size(); ++ i)
    	{
    		if (s[i]>='a' && s[i]<='z')
    		{
    			str.append(1, s[i]);
    			str.append(1, '/');    			
    		} else if (s[i]>='A' && s[i]<='Z')
    		{
    			str.append(1, s[i]-'A'+'a');
    			str.append(1, '/');
    		} else if (s[i]>='0' && s[i]<='9')
    		{
    			str.append(1, s[i]);
    			str.append(1, '/');
    		}
    	}
    	int mid = str.size() / 2;
    	for (int i = 1; mid-i>=0 && mid+i<str.size(); ++ i)
    	{
    		if (str[mid-i] != str[mid+i])
    		{
    			return false;
    		}
    	}
    	return true;
    }
};