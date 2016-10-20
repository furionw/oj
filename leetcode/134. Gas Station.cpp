class Solution 
{
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) 
    {
    	int gas_in_car = 0;
    	int begin = 0;

    	for (int now=0, end=0, station_cnt=0; station_cnt < gas.size(); ++ station_cnt)
    	{
    		gas_in_car = gas_in_car + gas[now] - cost[now];
    		if (gas_in_car < 0) // backward
    		{
    			-- begin;
    			begin = begin<0? gas.size()-1: begin;
    			now = begin;
    		} else // forward
    		{
    			++ end;
    			now = end;
    		}
    	}

    	return gas_in_car>=0? begin: -1;
    }
};