// Copyright 2020 Qi Wang
// Date: 2020-05-22
class Solution {
  public boolean isAlienSorted(String[] words, String order) {
    Map<Character, Integer> charToOrderMap = new HashMap<Character, Integer>();
    for (int i = 0; i < order.length(); ++i) {
      charToOrderMap.put(order.charAt(i), i);
    }
    for (int i = 0; i + 1 < words.length; ++i) {
      if (greater(words[i], words[i + 1], charToOrderMap)) {
        return false;
      }
    }
    return true;
  }

  private boolean greater(String a, String b, Map<Character, Integer> charToOrderMap) {
    int i = 0, j = 0;
    for (; i < a.length() && j < b.length(); ++i, ++j) {
      int o1 = charToOrderMap.get(a.charAt(i)), o2 = charToOrderMap.get(b.charAt(j));
      if (o1 > o2) {
        return true;
      } else if (o1 < o2) {
        return false;
      }
    }
    return a.length() > b.length();
  }
}
