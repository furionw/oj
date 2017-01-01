// Copyright 2016 Qi Wang
// Date: 2017-01-01
// This impl is faster than the one on 2016-12-14
class Solution {
 public:
  int findRadius(vector<int>& houses, vector<int>& heaters) {
    int minR = INT_MIN;
    sort(heaters.begin(), heaters.end());
    for (auto house : houses) {
      // upper_bound : return *it larger than val(house)
      auto it = upper_bound(heaters.begin(), heaters.end(), house);
      // all heaters <= house
      if (it == heaters.end()) {
        minR = max(minR, house - heaters.back());
      } else {
        int r = *it - house;
        if (it != heaters.begin()) r = min(r, house - *--it);
        minR = max(minR, r);
      }
    }
    return minR;
  }
};

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
