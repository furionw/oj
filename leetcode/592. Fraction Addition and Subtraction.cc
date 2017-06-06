// Copyright 2017 Qi Wang
// Date: 2017-06-06
struct Fraction {
  Fraction() {}
  Fraction(int n, int d) : numerator(n), denominator(d) {}
 
  Fraction& operator +=(const Fraction& other) {
    int n = numerator * other.denominator + denominator * other.numerator;
    int d = denominator * other.denominator;
    for (int i = 2; i <= abs(n) && i <= abs(d); ++i)
      while (n % i == 0 && d % i == 0)
        n /= i, d /= i;
    numerator = n;
    denominator = 0 != n ? d : 1;
    return *this;
  }
 
  string to_string() const {
    return ::to_string(numerator) + "/" + ::to_string(denominator);
  }
 
  int numerator = 0, denominator = 1;
};
 
class Solution {
 public:
  string fractionAddition(string expr) {
    Fraction result;
    for (size_t i = 0; i < expr.size();) {
      size_t pos = expr.find('/', i);
      size_t pos2 = min(expr.find('+', pos), expr.find('-', pos));
      result += Fraction(stoi(expr.substr(i, pos - i)),
          stoi(expr.substr(pos + 1, pos2 - pos - 1)));
      i = pos2;
    }
    return result.to_string();
  }
};
