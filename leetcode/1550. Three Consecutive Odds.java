// Date: 2020-08-19
class Solution {
  public boolean threeConsecutiveOdds(int[] arr) {
    int cnt = 0;
    for (int num : arr) {
      if ((num & 1) == 1) {
        if (++cnt == 3) {
          return true;
        }
      } else {
        cnt = 0;
      }
    }
    return false;
  }
}
