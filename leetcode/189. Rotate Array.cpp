// O(n) space
class Solution 
{
public:
    void rotate(int nums[], int n, int k) 
    {
        int new_nums[n];
        for (int i = 0; i < n; ++ i)
        {
        	new_nums[(i+k)%n] = nums[i];
        }
        for (int i = 0; i < n; ++ i)
        {
        	nums[i] = new_nums[i];
        }
    }
};