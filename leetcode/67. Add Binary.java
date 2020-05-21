// Copyright 2020 Qi Wang
// Date: 2020-03-21
class Solution {
  public String addBinary(String a, String b) {
    StringBuilder builder = new StringBuilder();
    int carry = 0;
    int i = a.length() - 1, j = b.length() - 1;
    while (i >= 0 && j >= 0) {
      int sum = a.charAt(i) - '0' + b.charAt(j) - '0' + carry;
      carry = sum / 2;
      builder.append('0' + (sum % 2));
      --i;
      --j;
    }
    if (i >= 0) {
      carry = addBinary(builder, a, i, carry);
    } else if (j >= 0) {
      carry = addBinary(builder, b, j, carry);
    }
    if (carry == 1) {
      builder.append('1');
    }
    return builder.reverse().toString();
  }

  private int addBinary(StringBuilder builder, String str, int idx, int carry) {
    if (carry == 0) {
      builder.append(str.substring(0, idx + 1));
      return 0;
    }
    for (; idx >= 0; --idx) {
      int sum = str.charAt(idx) - '0' + carry;
      carry = sum / 2;
      builder.append('0' + (sum % 2));
    }
    return carry;
  }
}