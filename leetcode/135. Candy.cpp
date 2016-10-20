// O(n) time, O(n) space
class Solution 
{
public:
    int candy(vector<int> &ratings) 
    {
    	vector<int> candy(ratings.size(), 1);    

    	for (int pre_child_candy=1, i=1; i < ratings.size(); ++ i)
    	{
    		if (ratings[i] > ratings[i-1])
    		{
    			candy[i] = ++ pre_child_candy;
    		} else
    		{
    			pre_child_candy = 1;
    		}
    	}
    	for (int pre_child_candy=1, i=static_cast<int>(ratings.size())-2; i >= 0; -- i)
    	{
    		if (ratings[i] > ratings[i+1])
    		{
    			candy[i] = max(++ pre_child_candy, candy[i]);
    		} else
    		{
    			pre_child_candy = 1;
    		}
    	}

    	return accumulate(candy.begin(), candy.end(), 0);
    }
};