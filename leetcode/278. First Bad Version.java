// Date: 2020-08-02

public class Solution extends VersionControl {
  public int firstBadVersion(int n) {
    int l = 1;
    int r = n;
    while (l <= r) {
      int mid = l + (r - l) / 2;
      if (isBadVersion(mid)) {
        r = mid - 1;
      } else {
        l = mid + 1;
      }
    }
    return l;
  }
}
