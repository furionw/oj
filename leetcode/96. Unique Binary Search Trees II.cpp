class Solution 
{
public:
    vector<TreeNode *> generateTrees(int n) 
    {
    	return generate(1, n);
    }
private:
	vector<TreeNode *> generate(int begin, int end)
	{
		vector<TreeNode *> ret;

		for (int i = begin; i <= end; ++ i)
		{
			auto left = generate(begin, i-1);
			auto right = generate(i+1, end);
			for (size_t j = 0; j < left.size(); ++ j)
			{
				for (size_t k = 0; k < right.size(); ++ k)
				{
					ret.push_back( new TreeNode(i) );
					ret.back()->left = left[j];
					ret.back()->right = right[k];
				}
			}
		}

		if ( ret.empty() == true )
		{
			ret.push_back( NULL );
		}
		return ret;
	}
};