// Date: 2022-10-11
class Solution {
 public:
  string shiftingLetters(string s, vector<vector<int>>& shifts) {
    vector<int> incBegins(s.size(), 0);
    vector<int> incEnds(s.size(), 0);
    vector<int> deBegins(s.size(), 0);
    vector<int> endBegins(s.size(), 0);
    for (const auto& shift : shifts) {
      int begin = shift[0];
      int end = shift[1];
      if (shift[2] == 1) {
        ++incBegins[begin];
        if (end + 1 < incEnds.size()) {
          ++incEnds[end + 1];
        }
      } else {
        ++deBegins[begin];
        if (end + 1 < endBegins.size()) {
          ++endBegins[end + 1];
        }
      }
    }

    int delta = 0;
    for (size_t i = 0; i < s.size(); ++i) {
      delta += incBegins[i] + endBegins[i];
      delta -= deBegins[i] + incEnds[i];
      delta %= 26;
      // printf("s[i] = %c, %d\n", s[i], (s[i] - 'a' + delta) % 26);
      s[i] = (s[i] - 'a' + delta + 26) % 26 + 'a';
    }
    return s;
  }
};
