/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */

bool cmp(const Interval& a, const Interval& b)
{
	if (a.start != b.start)
	{
		return a.start < b.start;
	} else 
	{
		return a.end < b.end;
	}
}

class Solution 
{
public:
    vector<Interval> merge(vector<Interval> &intervals) 
    {
    	if (intervals.empty() == true)
    	{
    		return vector<Interval>();
    	}
    	vector<Interval> ret;
    	Interval pre = intervals[0];

    	sort (intervals.begin(), intervals.end(), cmp);
    	for (size_t i = 1; i < intervals.size(); ++ i)
    	{
    		if (pre.end < intervals[i].start)
    		{
    			ret.push_back( pre );
    			pre = intervals[i];
    		} else if (pre.end>=intervals[i].start && pre.end<=intervals[i].end)
    		{
    			pre.end = intervals[i].end;
    		}
    	}
    	ret.push_back( pre );

    	return ret;
    }
};