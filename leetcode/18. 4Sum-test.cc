#include <set>
#include <unordered_map>
#include <vector>
#include <list>

using namespace std;

struct comp {
  inline bool operator ()(const vector<int>& lhs, const vector<int>& rhs) const {
    for (size_t i = 0; i < 4; ++i)
      if (lhs[i] != rhs[i])
        return lhs[i] < rhs[i];
    return false;
  }
};

class Solution {
 public:
  vector<vector<int>> fourSum(vector<int>& nums, int target) {
    vector<vector<int>> res;
    // trivial case
    if (nums.size() < 4) return res;
    // non-trivial case
    set<vector<int>, comp> resSet;    
    unordered_map<int, list<pair<int, int>>> pairs;
    for (int i = 0; i < nums.size(); ++i)
      for (int j = i + 1; j < nums.size(); ++j) {
        if (i == j) continue;
        pairs[nums[i] + nums[j]].emplace_back(i, j);
      }
    for (auto& num1ToPairs : pairs) {
      auto it = pairs.find(target - num1ToPairs.first);
      if (it == pairs.end()) continue;
      for (auto& p2 : it->second)
        for (auto& p1 : num1ToPairs.second) {
          // p1+p2 contain less than 4 elements, thus we just continue
          if (p1.first == p2.first || p1.first == p2.second
              || p1.second == p2.first || p1.second == p2.second) continue;
          vector<int> quadruplet {nums[p1.first], nums[p1.second],
              nums[p2.first], nums[p2.second]};
          // sort this quadruplet in order to judge whether it exists before
          sort(quadruplet.begin(), quadruplet.end());
          if (resSet.find(quadruplet) == resSet.end()) {
            res.push_back(quadruplet);
            resSet.insert(quadruplet);
          }
        }
    }
    return res;
  }
};

int main() {}