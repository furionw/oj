// 2025-07-16
class Solution {
 public:
  vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
    vector<int> result;
    list<int> visited;
    int maxCovered = -1;
    for (int i = 0; i < nums.size(); ++i) {
      for (; !visited.empty() && i - visited.front() > k; visited.pop_front()) {}
      visited.push_back(i);
      if (nums[i] == key) {
        maxCovered = i + k;
      }
      if (maxCovered >= i) {
        for (int idx : visited) {
          result.push_back(idx);
        }
        visited.clear();
      }
    }
    return result;
  }
};
