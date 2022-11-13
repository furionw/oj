// Date: 2022-11-12
class Solution {
 public:
  int distinctAverages(vector<int>& nums) {
    multiset<int> m;
    set<double> avgs;
    for (int num : nums) {
      m.insert(num);
    }
    while (!m.empty()) {
      int smallest = *m.begin();
      int largest = *m.rbegin();
      avgs.insert((smallest + largest) / 2.);
      m.erase(m.begin());
      m.erase(--m.end());
    }
    return avgs.size();
  }
};
