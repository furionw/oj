class Solution 
{
public:
    int hammingWeight(uint32_t n) 
    {
        int one_cnt = 0;
        for (uint32_t mask = 1; mask != 0; mask <<= 1)
        {
            one_cnt += (n & mask) != 0? 1: 0;
        }
        return one_cnt;
    }
};