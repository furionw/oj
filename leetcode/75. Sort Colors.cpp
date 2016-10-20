class Solution 
{
public:
    void sortColors(int A[], int n) 
    {
        int red=0, white=0;
        for (int i = 0; i < n; ++ i)
        {
        	if (A[i] == WHITE)
        	{
        		A[i] = BLUE;
        		A[white ++] = WHITE;
        	} else if (A[i] == RED)
        	{
        		A[i] = BLUE;
        		A[white ++] = WHITE;
        		A[red ++] = RED;
        	}
        }
    }
private:
	const int RED = 0;
	const int WHITE = 1;
	const int BLUE = 2;
};