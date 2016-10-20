class Solution 
{
public:
    string shortestPalindrome(string s) 
    {
    	string str(2*s.size()+1, 0);
    	for (size_t i = 1; i < str.size(); i += 2)
    	{
    		str[i] = s[i>>1];
    	}
    	vector<int> p(2*s.size()+1, 0);
    	int id=0, mx=0;
    	for (int i = 1; i < str.size(); ++ i)
    	{
    		p[i] = mx>i? min(p[2*id-i], mx-i): 0;
    		for (; i-p[i]-1>=0 && i+p[i]+1<str.size() 
    			&& str[i-p[i]-1]==str[i+p[i]+1]; ++ p[i]) {}
    		if (i + p[i] > mx)
    		{
    			mx = i + p[i];
    			id = i;
    		}
    	}

    	int max_length = 0;
    	for (int i = 1; i < str.size(); ++ i)
    	{
    		max_length = i==p[i]? i: max_length;
    	}
    	string non_palindrome_postfix = s.substr(max_length);
    	reverse(non_palindrome_postfix.begin(), non_palindrome_postfix.end());
    	return non_palindrome_postfix + s;
    }
};