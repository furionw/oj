// Date: 2020-08-02
// loop invariant: answer exists in [left, right]
public class Solution extends GuessGame {
  public int guessNumber(int n) {
    int left = 1;
    int right = n;
    while (left < right) {
      int mid = (right - left) / 2 + left;
      switch (guess(mid)) {
        case 0:
          return mid;
        case -1:
          right = mid - 1;
          break;
        case 1:
          left = mid + 1;
      }
    }
    return left;
  }
}

// Date: 2020-08-02
// loop invariant: answer exists in [left, right]
public class Solution extends GuessGame {
  public int guessNumber(int n) {
    int left = 1;
    int right = n;
    while (left <= right) {
      int mid = (right - left) / 2 + left;
      switch (guess(mid)) {
        case 0:
          return mid;
        case -1:
          right = mid - 1;
          break;
        case 1:
          left = mid + 1;
      }
    }
    return 0; // only used to comfort the compiler
  }
}
