// 2025-06-10
class Solution {
 public:
  vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    // deque is more performant than list
    deque<int> maxs;
    for (int i = 0; i < k - 1; ++i) {
      for (; !maxs.empty() && nums[maxs.back()] <= nums[i]; maxs.pop_back()) {}
      maxs.push_back(i);
    }

    vector<int> result;
    for (int i = k - 1; i < nums.size(); ++i) {
      for (; !maxs.empty() && nums[maxs.back()] <= nums[i]; maxs.pop_back()) {}
      maxs.push_back(i);
      for (; i - maxs.front() >= k; maxs.pop_front()) {}
      result.push_back(nums[maxs.front()]);
    }
    return result;
  }
};

// 2025-06-10
class Solution {
 public:
  vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    vector<int> result;
    priority_queue<pair<int, int>> pq;
    for (int i = 0; i < nums.size(); ++i) {
      pq.emplace(nums[i], i);
      // e.g. k = 3, i = 2
      if (i >= k - 1) {
        while (!pq.empty()) {
          auto [num, idx] = pq.top();
          // e.g. k = 3, i = 3
          //   idx = 0 -> discard
          //   idx = 1 -> select
          if (i - idx >= k) {
            pq.pop();
          } else {
            result.push_back(num);
            break;
          }
        }
      }
    }
    return result;
  }
};

// Date: 2017-09-12
class Solution {
 public:
  vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    list<pair<int, int>> maxs;
    for (int i = 0; i < k - 1; ++i) {
      AppendMaxList(&maxs, nums[i], i);
    }
    vector<int> result;
    for (int i = k - 1; i < nums.size(); ++i) {
      AppendMaxList(&maxs, nums[i], i);
      if (i - maxs.front().second >= k) {
        maxs.pop_front();
      }
      result.push_back(maxs.front().first);
    }
    return result;
  }

 private:
  void AppendMaxList(list<pair<int, int>>* maxs, int val, int idx)
      const {
    while (!maxs->empty() && val > maxs->back().first) {
      maxs->pop_back();
    }
    maxs->emplace_back(val, idx);
  }
};

// Date: 2017-08-10
class Solution {
 public:
  vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    if (nums.empty()) return {};
    list<int> non_incresing_list;
    for (int i = 0; i < k; ++i) {
      TryToPush(&non_incresing_list, nums[i]);
    }
    vector<int> result(1, non_incresing_list.front());
    for (int i = k; i < nums.size(); ++i) {
      if (non_incresing_list.front() == nums[i - k]) {
        non_incresing_list.pop_front();
      }
      TryToPush(&non_incresing_list, nums[i]);
      result.push_back(non_incresing_list.front());
    }
    return result;
  }
 
 private:
  void TryToPush(list<int>* non_incresing_list, int num) const {
    while (!non_incresing_list->empty() && num > non_incresing_list->back()) {
      non_incresing_list->pop_back();
    }
    non_incresing_list->push_back(num);
  }
};

// Solved by my own!!!
// Date: 2016-12-17
class Solution {
 public:
  vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    if (k == 1) return nums;
    vector<int> res;
    list<int> descL;
    for (int i = 0; i < k - 1; ++i) {
      while (!descL.empty() && descL.back() < nums[i]) descL.pop_back();
      descL.push_back(nums[i]);
    }
    for (size_t i = k - 1; i < nums.size(); ++i) {
      if (descL.front() == nums[i - k]) descL.pop_front();
      while (!descL.empty() && descL.back() < nums[i]) descL.pop_back();
      descL.push_back(nums[i]);
      res.push_back(descL.front());
    }
    return res;
  }
};

// Refer to: http://blog.csdn.net/xudli/article/details/46955257
// Time complexity: O(n)
// Date: 2016-11-12
class Solution {
 public:
  vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    if (k == 0) return vector<int>();
    vector<int> res;
    list<size_t> window;
    for (size_t i = 0; i < nums.size(); ++i) {
      while (!window.empty() && nums[window.back()] <= nums[i])
        window.pop_back();
      window.push_back(i);
      if (i - window.front() >= k) window.pop_front();
      if (i + 1 >= k) res.push_back(nums[window.front()]);
    }
    return res;
  }
};

// Date: 2016-11-11
struct cmp {
  bool operator ()(const pair<int, size_t>& lhs, const pair<int, size_t>& rhs) {
    return lhs.first != rhs.first
        ? lhs.first < rhs.first
        : lhs.second > rhs.second;
  }
};

class Solution {
 public:
  vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    if (k == 0) return vector<int>();
    vector<int> res;
    priority_queue<pair<int, size_t>, vector<pair<int, size_t>>, cmp> q;
    for (size_t i = 0; i < k; ++i)
      q.emplace(nums[i], i);
    res.push_back(q.top().first);
    for (size_t i = k; i < nums.size(); ++i) {
      q.emplace(nums[i], i);
      while (i - q.top().second >= k)
        q.pop();
      res.push_back(q.top().first);
    }
    return res;
  }
};
