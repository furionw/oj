class Solution 
{
public:
    vector<int> plusOne(vector<int> &digits) 
    {
    	int carry = 1;
    	vector<int> ret;

    	for (int i = digits.size()-1; i >= 0; -- i)
    	{
    		ret.insert(ret.begin(), (digits[i]+carry)%10);
    		carry = (digits[i] + carry) / 10;
    	}
    	if (carry != 0) // carry == 1
    	{
    		ret.insert(ret.begin(), 1);
    	}

    	return ret;
    }
};