// 2025-06-16
class Solution {
 public:
  int maxDistToClosest(vector<int>& seats) {
    int result = 0;

    int n = seats.size();
    bool foundFirst = false;
    int last = 0;
    for (int i = 0; i < n; ++i) {
      if (seats[i] == 0) {
        continue;
      }
      if (foundFirst == false) {
        foundFirst = true;
        result = i - last;
        last = i;
        continue;
      }
      result = max(result, (i - last) / 2);
      last = i;
    }
    result = max(result, n - 1 - last);

    return result;
  }
};
