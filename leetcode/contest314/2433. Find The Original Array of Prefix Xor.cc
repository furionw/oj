// Date: 2022-10-08
class Solution {
 public
  vector<int> findArray(vector<int>& pref) {
    auto result = pref;
    for (int i = 1; i < pref.size(); ++i) {
      result[i] ^= pref[i - 1];
    }
    return result;
  }
};