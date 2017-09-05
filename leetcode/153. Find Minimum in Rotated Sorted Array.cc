// Copyright 2017 Qi Wang
// Date: 2017-09-04
class Solution {
 public:
  int findMin(vector<int>& nums) {
    if (nums.empty()) return -1;
    return FindMinimal(nums, 0, nums.size() - 1);
  }
 
 private:
  int FindMinimal(const vector<int>& nums, int start, int end) {
    if (start + 1 >= end) {
      return min(nums[start], nums[end]);
    } else if (nums[start] <= nums[end]) {
      return nums[start];
    } else {
      int mid = start + end >> 1;
      return min(FindMinimal(nums, start, mid),
                 FindMinimal(nums, mid + 1, end));
    }
  }
};

class Solution 
{
public:
    int findMin(vector<int> &num) 
    {
        return binary_search(0, num.size()-1, num);
    }
private:
	int binary_search(int begin, int end, vector<int>& num)
	{
		if (num[begin] < num[end] || end - begin <= 1)
		{
			return min(num[begin], num[end]);
		} else if (num[begin] > num[(begin+end)>>1])
		{
			return binary_search(begin, (begin+end)>>1, num); 			
		} else
		{
			return binary_search(((begin+end)>>1)+1, end, num);			
		}
	}
};