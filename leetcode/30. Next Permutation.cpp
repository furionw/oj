class Solution 
{
public:
    void nextPermutation(vector<int> &num) 
    {
		for (int i = num.size()-2; i >= 0; -- i)
		{
			for (int j = num.size()-1; j > i; -- j)
			{
				if (num[j] > num[i])
				{
					int tmp = num[j];
					num[j] = num[i];
					num[i] = tmp;
					sort(num.begin()+i+1, num.end()); 
					return ;
				}
			}
		}
		sort(num.begin(), num.end());
    }
};