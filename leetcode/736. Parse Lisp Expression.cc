// Date: 2022-10-16
class Solution {
 public:
  int evaluate(string expr) {
    vector<Scope> scopes;
    return eval(expr, scopes);
  }
  
 private:
  using Scope = map<string, int>;
  
  int eval(
      const string& expr,
      vector<Scope>& scopes) {
    if (expr[0] == '(') {
      return eval(expr.substr(1, expr.size() - 2), scopes);
    }
    auto tokens = tokenize(expr);
    int res = -1;
    if (tokens[0] == "let") {
      scopes.emplace_back();
      for (size_t i = 1; i + 1 < tokens.size(); i += 2) {
        scopes.back()[tokens[i]] = eval(tokens[i + 1], scopes);
      }
      res = eval(tokens.back(), scopes);
      scopes.pop_back();
    } else if (tokens[0] == "add") {
      res = eval(tokens[1], scopes) + eval(tokens[2], scopes);
    } else if (tokens[0] == "mult") {
      res = eval(tokens[1], scopes) * eval(tokens[2], scopes);
    } else if (tokens[0][0] == '-' || isdigit(tokens[0][0])) {
      res = stoi(tokens[0]);
    } else {
      for (auto it = scopes.rbegin(); it != scopes.rend(); ++it) {
        if (it->count(tokens[0])) {
          res = (*it)[tokens[0]];
          break;
        }
      }
    }
    return res;
  }

  vector<string> tokenize(const string& expr) {
    vector<string> tokens;
    for (size_t i = 0; i < expr.size();) {
      if (expr[i] == '(') {
        size_t next = i + 1, p = 1;
        for (; next < expr.size() && p > 0; ++next) {
          if (expr[next] == '(') {
            ++p;
          } else if (expr[next] == ')') {
            --p;
          }
        }
        tokens.push_back(expr.substr(i + 1, next - i - 2));
        i = next + 1;
      } else {
        size_t next = expr.find(' ', i);
        if (next == string::npos) {
          tokens.push_back(expr.substr(i));
          break;
        } else {
          tokens.push_back(expr.substr(i, next - i));
          i = next + 1;
        }
      }
    }
    return tokens;
  }
};