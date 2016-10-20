class Solution 
{
public:
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) 
    {
    	vector<Interval> ret;

        for (auto it = intervals.begin(); it != intervals.end(); ++ it)
        {
        	if (it->end<newInterval.start || it->start>newInterval.end)
        	{
        		ret.push_back( *it );
        	} else if (it->start<newInterval.start &&
        		it->end>=newInterval.start && it->end<=newInterval.end)
        	{
        		newInterval.start = it->start;
        	} else if (it->end>newInterval.end &&
        		it->start>=newInterval.start && it->start<=newInterval.end)
        	{
        		newInterval.end = it->end;
        	} else if (it->start<=newInterval.start && it->end>=newInterval.end)
        	{
        		newInterval.start = it->start;
        		newInterval.end = it->end;
        	}
        }
        auto it = ret.begin();
        for ( ; it != ret.end(); ++ it)
        {
        	if (it->start > newInterval.end)
        	{
        		intervals.insert(it, newInterval);
        		break;
        	}
        }
        if (it == ret.end())
        {
        	ret.push_back( newInterval );
        }

        return ret;
    }
};