// Copyright 2016 Qi Wang
// Date: 2016-10-24
// O(n(logn + n/k))
class Solution {
 public:
  bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
    pair<long long, int> nodes[nums.size()];
    for (size_t i = 0; i < nums.size(); ++i)
      nodes[i] = make_pair<long long, int>(nums[i], i);
    sort(nodes, nodes + nums.size());
    for (size_t i = 0; i < nums.size(); ++i)
      for (size_t j = i + 1; j < nums.size()
          && abs(nodes[i].first - nodes[j].first) <= t; ++j)
        if (abs(nodes[i].second - nodes[j].second) <= k) return true;
    return false;
  }
};

// Date: 2016-10-24
// O(nlogk)
class Solution {
 public:
  bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
    set<long long> s;
    for (size_t i = 0; i < nums.size(); ++i) {
      if (s.size() == k + 1) s.erase(nums[i - k - 1]);
      auto it = s.lower_bound(long(nums[i]) - t);
      if (it != s.end() && *it <= long(nums[i]) + t) return true;
      s.insert(nums[i]);
    }
    return false;
  }
};

// Date: 2015-01
class Solution 
{
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t)
    {
        multiset<long long> bst;
        for (size_t i = 0; i < nums.size(); ++ i)
        {
        	if (bst.size() == k+1)
        	{
        		bst.erase(nums[i-k-1]);
        	}
        	auto lb = bst.lower_bound(nums[i]-t);
        	if (lb!=bst.end() && *lb-nums[i]<=t)
        	{
        		return true;
        	}
        	bst.insert(nums[i]);
        }
        return false;
    }
};