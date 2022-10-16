// Date: 2022-10-15
class Solution {
 public:
  string largestPalindromic(string num) {
    map<char, int> cntByDigit;
    for (char c : num) {
      ++cntByDigit[c];
    }

    string res;
    for (auto it = cntByDigit.rbegin(); it != cntByDigit.rend(); ++it) {
      if (it->second & 1) {
        res = it->first;
        break;
      }
    }

    string leadingHalf;
    for (auto it = cntByDigit.rbegin(); it != cntByDigit.rend(); ++it) {
      int pairs = it->second / 2;
      leadingHalf += string(pairs, it->first);
    }
    if (!leadingHalf.empty() && leadingHalf[0] != '0') {
      res = leadingHalf + res;
      reverse(leadingHalf.begin(), leadingHalf.end());
      res += leadingHalf;
    }
    
    return res.empty() ? "0" : res;
  }
};
