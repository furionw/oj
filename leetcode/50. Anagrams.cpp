class Solution 
{
public:
    vector<string> anagrams(vector<string> &strs) 
    {
        map<string, int> record;
        vector<string> ret;
        
        for (size_t i = 0; i < strs.size(); ++ i)
        {
        	string cur = strs[i];
        	sort(cur.begin(), cur.end());
        	if (record.count(cur) == 0)
        	{
        		record[cur] = i;
        	} else if (record[cur] != -1) // first time
        	{
        		ret.push_back( strs[record[cur]] );
        		ret.push_back( strs[i] );
        		record[cur] = -1;
        	} else
        	{
        		ret.push_back( strs[i] );
        	}
        }

        return ret;
    }
};