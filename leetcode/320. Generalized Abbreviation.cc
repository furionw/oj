// Copyright 2017 Qi Wang
// Date: 2017-08-15
// Congratulations Qi. Your solution seems concise!
class Solution {
 public:
  vector<string> generateAbbreviations(string word) {
    vector<string> result;
    F(word, 0, "", 0, &result);
    return result;
  }
 
 private:
  void F(const string& word, int idx, string cur, int acc,
         vector<string>* result) const {
    if (idx == word.size()) {
      if (acc > 0) cur += to_string(acc);
      result->push_back(cur);
      return;
    }
    F(word, idx + 1, cur + (acc > 0 ? to_string(acc) : "") + word[idx], 0,
        result);
    F(word, idx + 1, cur, acc + 1, result);
  }
};

// Date: 2016-12-28
// Method 2: refer to the Top Solutions
class Solution {
 public:
  vector<string> generateAbbreviations(string word) {
    vector<string> res;
    f(word, 0, "", 0, res);
    return res;
  }

 private:
  void f(const string& word, size_t pos, const string& cur, size_t cnt,
      vector<string>& res) const {
    if (pos == word.size()) {
      res.push_back(cur + (cnt != 0 ? to_string(cnt) : ""));
    } else {
      f(word, pos + 1, cur, cnt + 1, res);
      f(word, pos + 1, cur + (cnt != 0 ? to_string(cnt) : "") + word[pos],
          0, res);
    }
  }
};

// Date: 2016-12-28
// Method 1
class Solution {
 public:
  vector<string> generateAbbreviations(string word) {
    if (word.empty()) return vector<string>(1, "");
    vector<string> res;
    if (word.size() == 1) {
      res.push_back(word);
      res.push_back("1");
      return res;
    }
    auto subRes = generateAbbreviations(word.substr(1));
    for (auto& abbr : subRes) {
      if (digit(abbr[0])) {
        size_t len = 1;
        for(; len < abbr.size() && digit(abbr[len]); ++len) {}
        int num = stoi(abbr.substr(0, len));
        res.push_back(to_string(++num) + abbr.substr(len));
        res.push_back(word.substr(0, 1) + move(abbr));
      } else {
        res.push_back(string("1") + abbr);
        res.push_back(word.substr(0, 1) + move(abbr));
      }
    }
    return res;
  }

 private:
  bool digit(char c) const { return '0' <= c && c <= '9'; }
};
