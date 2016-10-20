class Solution 
{
public:
    uint32_t reverseBits(uint32_t n) 
    {
    	uint32_t ret = 0;
    	for (int i = 0; i < 32; ++ i)
    	{
    		ret |= (((n&(1<<i))!=0)? (1<<(31-i)): 0);
    	}
    	return ret;
    }
};