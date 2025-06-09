// 2025-06-08
class Solution {
 public:
  int jump(vector<int>& nums) {
    int steps = 0;

    for (int l = 0, r = 0, m = 0; m < nums.size() - 1; ++steps) {
      for (int i = l; i <= r; ++i) {
        m = max(m, i + nums[i]);
      }
      l = r + 1;
      r = m;
    }

    return steps;
  }
};

// Date: 2016-11-25
class Solution {
 public:
  int jump(vector<int>& nums) {
    int step = 0;
    // "You can assume that you can always reach the last index."
    // So the "max" is always updated in each iteration
    for (size_t i = 0, next = 0, max = 0; max + 1 < nums.size(); ++step) {
      for (; i <= max; ++i) next = std::max(next, i + nums[i]);
      max = next;
    }
    return step;
  }
};

// Date: 2014-07
class Solution 
{
public:
    int jump(int A[], int n) 
    {
      int step = 0;

      for (int i=0, bound=0, next=0; next < n - 1; ++ step)
      {
          for ( ; i <= bound; ++ i)
          {
            next = max(next, i+A[i]);
          }
          bound = next;
      }

      return step;
    }
};