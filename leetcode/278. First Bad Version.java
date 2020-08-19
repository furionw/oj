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

// Date: 2020-05-24
// Refer to Xiaohan's solution
public class Solution extends VersionControl {
  public int firstBadVersion(int n) {
    int left = 1, right = n;
    while (left < right) {
      int mid = left + (right - left) / 2;
      if (isBadVersion(mid)) {
        right = mid;
      } else {
        left = mid + 1;
      }
    }
    // left == right
    return right;
  }
}

// Date: 2020-05-24
public class Solution extends VersionControl {
  public int firstBadVersion(int n) {
    long l = 1, r = n;
    int prev = 0;
    while (l <= r) {
      int mid = (int)((l + r) / 2);
      if (isBadVersion(mid)) {
        prev = mid;
      } else {
        l = mid + 1;
      }
    }
    return prev;
  }
}
