// 2025-05-01
// Method 1
class Solution {
 public:
  string applySubstitutions(vector<vector<string>>& replacements, string text) {
    // token replacements
    unordered_map<char, string> tRs;
    // token dependencies
    unordered_map<char, unordered_set<char>> tDeps;

    for (const auto& replacement: replacements) {
      char token = replacement[0][0];
      tRs[token] = replacement[1];
      tDeps[token] = getTokens(replacement[1]);
    }

    queue<char> q;
    for (const auto& [token, replacement] : tRs) {
      if (tDeps[token].empty()) {
        q.push(token);
      }
    }

    for (; !q.empty(); q.pop()) {
      char dest = q.front();
      for (auto& [src, deps] : tDeps) {
        if (!deps.contains(dest)) {
          continue;
        }
        deps.erase(dest);
        tRs[src] = replace(tRs[src], dest, tRs[dest]);
        if (deps.empty()) {
          q.push(src);
        }
      }
    }
    
    return replace(text, tRs);
  }

 private:
  unordered_set<char> getTokens(const string& str) {
    unordered_set<char> result;
    for (size_t i = str.find('%'); i < str.size(); i = str.find('%', i + 3)) {
      result.insert(str[i + 1]);
    }
    return result;
  }

  string replace(const string& str, char pattern, const string& r) {
    string result;
    string p = string("%") + pattern + "%";
    size_t cur = 0;
    size_t i = str.find(p);
    for (; i != string::npos; i = str.find(p, cur)) {
      result += str.substr(cur, i - cur) + r;
      cur = i + 3;
    }
    result += str.substr(cur);
    return result;
  }

  string replace(const string& str, unordered_map<char, string>& tRs) {
    string result;

    for (size_t i = 0; i < str.size(); i += 4) {
      if (!result.empty()) {
        result += "_";
      }
      result += tRs[str[i + 1]];
    }

    return result;
  }
};


// case 1: [["A", "abc"]], "%A%_%A%"
// tRs = {{"A", "abc"}}
// tDeps['A'] = {}
// iter 1
//   dest = 'A'
// replace("%A%_%A%", {{"A", "abc"}})

// Method 2
class Solution {
 public:
  string applySubstitutions(vector<vector<string>>& replacements, string text) {
    for (const auto& r : replacements) {
      dict[r[0][0]] = r[1];
    }
    return parse(text);
  }

 private:
  string parse(const string& text) {
    string result;

    for (size_t i = 0; i < text.size();) {
      if (text[i] != '%') {
        result += text[i];
        ++i;
      } else {
        char c = text[i + 1];
        if (dict[c].find('%') != string::npos) {
          dict[c] = parse(dict[c]);
        }
        result += dict[c];
        i += 3;
      }
    }

    return result;
  }

  unordered_map<char, string> dict;
};