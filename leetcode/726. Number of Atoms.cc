// Date: 2022-10-16
class Solution {
 public:
  string countOfAtoms(string formula) {
    auto cntByElem = foo(formula);
    string res;
    for (const auto& [elem, cnt] : cntByElem) {
      res += elem + (cnt > 1? to_string(cnt) : "");
    }
    return res;
  }
  
 private:
  map<string, int> foo(string formula) const {
    map<string, int> res;
    
    for (size_t i = 0, j = 0; i < formula.size(); i = j) {
      ++j;
      if (formula[i] == '(') {
        int p = 1;
        for (; p > 0 && j < formula.size(); ++j) {
          if (formula[j] == '(') {
            ++p;
          } else if (formula[j] == ')') {
            --p;
          }
        }
        // sub formula. e.g. (H)2, i == 0, j == 3
        auto sub = foo(formula.substr(i + 1, j - i - 2));
        int multi = getMulti(formula, j);
        for (const auto& [elem, cnt] : sub) {
          res[elem] += cnt * multi;
        }
      // formula[i] is a uppercase character
      } else {
        for (; j < formula.size() && islower(formula[j]); ++j) {}
        // e.g. Maga2, i = 0, j = 4
        string elem = formula.substr(i, j - i);
        int multi = getMulti(formula, j);
        res[elem] += multi;
      }
    }
    
    return res;
  }

  
  int getMulti(const string& formula, size_t& j) const {
    int multi = 1;
    if (j < formula.size() && isdigit(formula[j])) {
      multi = formula[j] - '0';
      for (++j; j < formula.size() && isdigit(formula[j]); ++j) {
        multi = 10 * multi + formula[j] - '0';
      }
    }
    return multi;
  }
};
