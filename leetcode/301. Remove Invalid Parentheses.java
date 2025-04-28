// Copyright 2020 Qi Wang
// Date: 2020-05-23
class Solution {
  public List<String> removeInvalidParentheses(String s) {
    if (s == null) {
      return new ArrayList<String>();
    }
    removeInvalidParentheses(
        new StringBuilder(), 0 /* balance */, 0 /* removes */, s, 0 /* idx */);
    return new ArrayList<String>(strs);
  }

  void removeInvalidParentheses(
      StringBuilder prefix, int balance, int removes, String s, int idx) {
    if (removes > minRemove) {
      return;  // pruning
    }
    if (idx == s.length()) {
      if (balance == 0) {
        if (removes < minRemove) {
          minRemove = removes;
          strs.clear();
          strs.add(prefix.toString());
        } else {
          strs.add(prefix.toString());
        }
      }
      return;
    }
    char c = s.charAt(idx);
    switch (c) {
      case '(':
        prefix.append(c);
        removeInvalidParentheses(prefix, balance + 1, removes, s, idx + 1);
        prefix.deleteCharAt(prefix.length() - 1);
        removeInvalidParentheses(prefix, balance, removes + 1, s, idx + 1);
        return;
      case ')':
        if (balance > 0) {
          prefix.append(c);
          removeInvalidParentheses(prefix, balance - 1, removes, s, idx + 1);
          prefix.deleteCharAt(prefix.length() - 1);
        }
        removeInvalidParentheses(prefix, balance, removes + 1, s, idx + 1);
        return;
      default:
        prefix.append(c);
        removeInvalidParentheses(prefix, balance, removes, s, idx + 1);
        prefix.deleteCharAt(prefix.length() - 1);
    }
  }

  int minRemove = Integer.MAX_VALUE;
  private Set<String> strs = new HashSet<String>();
}