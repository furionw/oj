// Copyright 2016 Qi Wang
// Date: 2016-12-14
class Solution {
 public:
  int findRadius(vector<int>& houses, vector<int>& heaters) {
    sort(heaters.begin(), heaters.end());
    // We can eliminate this desHeaters via implementing our own lower_bound()
    // & upper_bound() function
    vector<int> desHeaters(heaters.size());
    for (size_t i = 0; i < heaters.size(); ++i)
      desHeaters[heaters.size() - 1 - i] = heaters[i];
    int res = 0;
    for (int house : houses) {
      auto greater = lower_bound(heaters.begin(), heaters.end(), house);
      auto less = upper_bound(desHeaters.begin(), desHeaters.end(), house,
          std::greater<int>());
      if (greater != heaters.end() && less != desHeaters.end()) {
        res = max(res, min(*greater - house, house - *less));
      } else if (greater != heaters.end()) {
        res = max(res, *greater - house);
      } else if (less != desHeaters.end()) {
        res = max(res, house - *less);
      } else {
        res = max(res, house < heaters.front()
            ? heaters.front() - house : house - heaters.back());
      }
    }
    return res;
  }
};
