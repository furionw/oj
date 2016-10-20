class Solution 
{
public:
    vector<vector<int> > permute(vector<int> &num) 
    {
		vector<vector<int> > ret;	
		sort(num.begin(), num.end());

		do 
		{
			ret.push_back( num );
		} while( has_next_permutation(num) );

		return ret;
	}

private:
	bool has_next_permutation(vector<int>& num)
	{
		for (int i = num.size()-2; i >= 0; -- i)
		{
			for (int j = num.size()-1; j > i; -- j)
			{
				if (num[j] > num[i])
				{
					swap(num[i], num[j]);
					sort(num.begin()+i+1, num.end());
					return true;
				}
			}
		}
		return false;
	}
};