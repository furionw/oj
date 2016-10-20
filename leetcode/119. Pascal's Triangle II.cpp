class Solution 
{
public:
    vector<int> getRow(int rowIndex) 
    {
        vector<int> line, next_line;

        for (int i = 0; i <= rowIndex; ++ i)
        {
        	next_line.clear();
        	next_line.push_back(1);
        	for (int j = 0; j < line.size(); ++ j)
        	{
        		if (j+1 < line.size())
        		{
        			next_line.push_back( line[j] + line[j+1] );
        		} else
        		{
        			next_line.push_back( 1 );
        		}
        	}
        	line = next_line;
        }

        return line;
    }
};