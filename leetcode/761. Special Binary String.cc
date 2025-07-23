// 2025-07-22
class Solution {
 public:
  string makeLargestSpecial(string s) {
    int balance = 0;
    int stops = 0;
    for (char c : s) {
      balance += c == '1' ? 1 : -1;
      if (balance == 0) {
        ++stops;
      }
    }

    if (stops == 1) {
      auto subresult = makeLargestSpecial(s.substr(1, s.size() - 2));
      auto result = string("1") + subresult + "0";
      return result;
    }

    vector<string> tokens;
    string result;
    balance = 0;
    int lastEnd = 0;
    int currentBegin = 0;
    for (int i = 0; i < s.size(); ++i) {
      if (balance == 0) {
        currentBegin = i;
      }
      balance += s[i] == '1' ? 1 : -1;
      if (balance > 0) {
        continue;
      }
      if (!tokens.empty() && lastEnd + 1 < currentBegin) {
        sort(tokens.begin(), tokens.end(), greater<string>());
        for (auto&& token : tokens) {
          result += move(token);
        }
        tokens.clear();
      }
      tokens.push_back(makeLargestSpecial(s.substr(currentBegin, i - currentBegin + 1)));
      lastEnd = i;
    }
    sort(tokens.begin(), tokens.end(), greater<string>());
    for (auto&& token : tokens) {
      result += move(token);
    }
    return result;
  }
};
