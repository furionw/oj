// Copyright 2017 Qi Wang
// Date: 2017-06-08
class Solution {
 public:
  int shoppingOffers(vector<int>& price, vector<vector<int>>& special,
      vector<int>& needs) {
    int64_t result = INT_MAX;
    Foo(price, special, 0, needs, 0, &result);
    return result;
  }

 private:
  void Foo(const vector<int>& price,
      const vector<vector<int>>& special, size_t special_idx,
      vector<int>& cur_items, int64_t cur_price, int64_t* result) const {
    // prune
    if (cur_price > *result) {
      return;
    }
    // all zeros
    if (count(cur_items.begin(), cur_items.end(), 0) == cur_items.size()) {
      *result = cur_price;
      return;
    }
    if (special_idx == special.size()) {
      for (size_t i = 0; i < cur_items.size(); ++i)
        cur_price += cur_items[i] * price[i];
      *result = min(*result, cur_price);
      return;
    }
    Foo(price, special, special_idx + 1, cur_items, cur_price, result);
    int offer_cnt = 0;
    while (true) {
      bool can_buy = true;
      for (size_t i = 0; can_buy && i < cur_items.size(); ++i)
        can_buy = cur_items[i] >= special[special_idx][i];
      if (can_buy) {
        ++offer_cnt;
        for (size_t i = 0; i < cur_items.size(); ++i)
          cur_items[i] -= special[special_idx][i];
        cur_price += special[special_idx].back();
        Foo(price, special, special_idx + 1, cur_items, cur_price, result);
      } else {
        break;
      }
    }
    for (size_t i = 0; i < cur_items.size(); ++i)
      cur_items[i] += offer_cnt * special[special_idx][i];    
  }
};
