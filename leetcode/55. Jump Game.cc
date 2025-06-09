// 2025-06-08
class Solution {
 public:
  bool canJump(vector<int>& nums) {
    int longest = 0;
    for (int i = 0; i < nums.size() && longest < nums.size(); ++i) {
      if (longest < i) {
        return false;
      }
      longest = max(longest, i + nums[i]);
    }
    return longest >= nums.size() - 1;
  }
};


// Date: 2016-12-16
class Solution {
 public:
  bool canJump(vector<int>& nums) {
    if (nums.empty()) return true;
    int furthest = 0;
    for (int i = 0; i <= furthest && furthest < static_cast<int>(nums.size());
        ++i)
      furthest = max(furthest, i + nums[i]);
    return furthest >= nums.size() - 1;
  }
};

// Date: 2016-11-25
class Solution {
 public:
  // nums is an non-empty vector
  bool canJump(vector<int>& nums) {
    int max = 0;
    for (int i = 0; max + 1 < nums.size() && i <= max; ++i)
      max = std::max(max, i + nums[i]);
    return max + 1 >= nums.size();
  }
};

// Date: 2014-06
class Solution {
 public:
  bool canJump(int A[], int n) 
  {
    for (int i=0, bound=0; i <= bound; ++ i)
    {
      bound = max(A[i]+i, bound);
      if (bound >= n-1)
      {
        return true;
      }
    }
    return false;
  }
};