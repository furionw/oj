class Solution 
{
public:
    int rangeBitwiseAnd(int m, int n) 
    {
        int ret = 0;
        for (int i = 0; m!=0 && n!=0 && i<31; n>>=1, m>>=1, i++)
        {
        	ret += ((m%2!=0)&&m==n? (1<<i): 0);
        }
        return ret;
    }
};