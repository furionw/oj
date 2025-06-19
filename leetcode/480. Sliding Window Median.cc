// 2025-06-18
// Refer to https://leetcode.com/problems/sliding-window-median/description/?envType=company&envId=doordash&favoriteSlug=doordash-six-months
class Solution {
 public:
  vector<double> medianSlidingWindow(vector<int>& nums, int k) {
    priority_queue<int> lo;
    priority_queue<int, vector<int>, greater<int>> hi;
    unordered_map<int, int> invalids;
    // max and minHeap sizes
    // k = 4 -> 2, 2
    // k = 5 -> 3, 2
    for (int i = 0; i < k; ++i) {
      lo.push(nums[i]);
    }
    for (int i = 0; i < k / 2; ++i) {
      hi.push(lo.top());
      lo.pop();
    }

    vector<double> result;
    result.push_back((k % 2 == 1)
        ? lo.top()
        : (1. * lo.top() + hi.top()) / 2
    );

    for (int i = k; i < nums.size(); ++i) {
      ++invalids[nums[i - k]];

      int balance = nums[i - k] <= lo.top() ? -1 : 1;
      if (nums[i] <= lo.top()) {
        lo.push(nums[i]);
        ++balance;
      } else {
        hi.push(nums[i]);
        --balance;
      }

      if (balance < 0) {
        lo.push(hi.top());
        hi.pop();
      } else if (balance > 0) {
        hi.push(lo.top());
        lo.pop();
      }

      while (invalids[lo.top()] > 0) {
        --invalids[lo.top()];
        lo.pop();
      }
      while (!hi.empty() && invalids[hi.top()] > 0) {
        --invalids[hi.top()];
        hi.pop();
      }

      result.push_back((k % 2 == 1)
          ? lo.top()
          : (1. * lo.top() + hi.top()) / 2
      );
    }

    return result;
  }
};
