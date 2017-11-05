// Copyright 2017 Qi Wang
// Date: 2017-11-05
class Solution {
 public:
  vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> result;
    vector<int> cur;
    Subsets(nums, 0, &cur, &result);
    return result;
  }
 
 private:
  void Subsets(const vector<int>& nums, int idx, vector<int>* cur,
      vector<vector<int>>* result) const {
    if (idx == nums.size()) {
      result->push_back(*cur);
    } else {
      Subsets(nums, idx + 1, cur, result);
      cur->push_back(nums[idx]);
      Subsets(nums, idx + 1, cur, result);
      cur->pop_back();
    }
  }
};

// Date: 2017-07-22
// Method 2: refer to the solution in many years ago
class Solution {
 public:
  vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> result;
    vector<int> elem;
    F(nums, 0, elem, &result);
    return result;
  }

 private:
  void F(const vector<int>& nums, size_t idx, vector<int>& elem,
      vector<vector<int>>* result) const {
    if (idx == nums.size()) {
      result->push_back(elem);
      return;
    }
    // 1. didn't take
    F(nums, idx + 1, elem, result);
    // 2. take
    elem.push_back(nums[idx]);
    F(nums, idx + 1, elem, result);
    elem.pop_back();
  }
};

// Date: 2017-07-22
// Method 1
class Solution {
 public:
  vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> result(1, vector<int>());
    vector<int> elem;
    F(nums, 0, elem, &result);
    return result;
  }

 private:
  void F(const vector<int>& nums, size_t idx, vector<int>& elem,
      vector<vector<int>>* result) const {
    if (idx == nums.size()) return;
    // 1. didn't take
    F(nums, idx + 1, elem, result);
    // 2. take
    elem.push_back(nums[idx]);
    result->push_back(elem);
    F(nums, idx + 1, elem, result);
    elem.pop_back();
  }
};

class Solution 
{
public:
    vector<vector<int> > subsets(vector<int> &S) 
    {
    	sort(S.begin(), S.end());    
    	for (size_t i = 0; i <= S.size(); ++ i)
    	{
    		vector<int> now;
    		gao(now, 0, S, i);
    	}
    	return ret;
    }
private:
	void gao(vector<int>& now, size_t start, vector<int>& S, size_t k)
	{
		if (now.size() == k)
		{
			ret.push_back(now);
			return ;
		}
		for (size_t i = start; i < S.size(); ++ i)
		{
			now.push_back(S[i]);
			gao(now, i+1, S, k);
			now.pop_back();
		}
	}
	vector<vector<int>> ret;
};