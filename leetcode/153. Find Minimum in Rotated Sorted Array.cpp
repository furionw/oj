class Solution 
{
public:
    int findMin(vector<int> &num) 
    {
        return binary_search(0, num.size()-1, num);
    }
private:
	int binary_search(int begin, int end, vector<int>& num)
	{
		if (num[begin] < num[end] || end - begin <= 1)
		{
			return min(num[begin], num[end]);
		} else if (num[begin] > num[(begin+end)>>1])
		{
			return binary_search(begin, (begin+end)>>1, num); 			
		} else
		{
			return binary_search(((begin+end)>>1)+1, end, num);			
		}
	}
};