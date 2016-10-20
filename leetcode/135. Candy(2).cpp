class Solution 
{
public:
    int candy(vector<int> &ratings) 
    {
    	int tot = 1, dec_length = 0, candy_before_dec = 1, pre_child_candy = 1;

    	for (int i = 1; i < ratings.size(); ++ i)
    	{
    		if (ratings[i] > ratings[i-1])
    		{
    			tot += ++ pre_child_candy;
    			dec_length = 0;
    			candy_before_dec = pre_child_candy;
    		} else if (ratings[i] == ratings[i-1])
    		{
    			++ tot;    			
    			dec_length = 0;    			
    			candy_before_dec = pre_child_candy = 1;
    		} else // <
    		{
    			tot += ((++dec_length>=candy_before_dec)? 1: 0);
    			tot += dec_length;
    			pre_child_candy = 1;
    		}
    	}

    	return tot;
    }
};