class Solution 
{
public:
    bool isHappy(int n) 
    {
    	if (int_set.find(n) != int_set.end())
    	{
    		return false;
    	}
    	int_set.insert(n);

    	int new_num = 0;
    	for ( ; n != 0; n /= 10)
    	{
    		new_num += ((n % 10) * (n % 10));
    	}

    	return new_num==1 || isHappy(new_num);
    }

private:
	unordered_set<int> int_set;
};