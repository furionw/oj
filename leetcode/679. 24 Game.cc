// Copyright 2017 Qi Wang
// Date: 2017-09-16
// Case 1: [1, 2, 3, 4] => true
// Case 2: [4, 1, 8, 7] => ()
class Solution {
 public:
  bool judgePoint24(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    list<double> l;
    for (int num : nums) {
      l.push_back(num);
    }
    do {
      if (cal(l)) return true;
    } while (next_permutation(l.begin(), l.end()));
    return false;
  }

 private:
  bool cal(list<double> nums) {
    if (nums.size() == 1) {
      return nums.front() == 24;
    } else {
      for (auto itr = nums.begin(); itr != nums.end(); ++itr) {
        auto next = itr;
        if (++next == nums.end()) break;
        // insert_pos : variable used when restoring the environment
        auto insert_pos = next;
        ++insert_pos;
        // original values
        double cur = *itr;
        double cur_next = *next;
        // remove next
        nums.erase(next);
        // add
        *itr = cur + cur_next;
        if (cal(nums)) return true;
        // sub
        *itr = cur - cur_next;
        if (cal(nums)) return true;
        // mul
        *itr = cur * cur_next;
        if (cal(nums)) return true;
        // div
        if (cur_next != 0) {
          *itr = cur / cur_next;
          if (cal(nums)) return true;
        }
        // restore the environment
        *itr = cur;
        nums.insert(insert_pos, cur_next);
      }
    }
    return false;
  }
};
