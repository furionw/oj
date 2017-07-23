// Copyright 2017 Qi Wang
// Date: 2017-07-22
// Note that the previous solution is more concise
class Solution {
 public:
  void sortColors(vector<int>& nums) {
    if (nums.size() <= 1) return;
    int red_idx = 0, white_idx = 0, blue_idx = nums.size() - 1;
    while (white_idx <= blue_idx) {
      if (nums[white_idx] == 0) {
        if (white_idx == red_idx) {
          red_idx = white_idx = white_idx + 1;
        } else {
          swap(nums[red_idx++], nums[white_idx]);
        }
      } else if (nums[white_idx] == 1) {
        ++white_idx;
      // 2
      } else {
        swap(nums[white_idx], nums[blue_idx--]);
      }
    }
  }
};

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