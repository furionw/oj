// Copyright 2020 Qi Wang
// Date: 2020-05-23
class Solution {
  public boolean validPalindrome(String s) {
    for (int i = 0, j = s.length() -1; i < j; ++i, --j) {
      if (s.charAt(i) != s.charAt(j)) {
        return validPalindrome(s, i, j - 1) || validPalindrome(s, i + 1, j);
      }
    }
    return true;
  }

  public boolean validPalindrome(String s, int i, int j) {
    for (; i < j && s.charAt(i) == s.charAt(j); ++i, --j) {}
    return i >= j;
  }
}
