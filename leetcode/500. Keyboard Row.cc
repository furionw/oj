// Copyright 2017 Qi Wang
// Date: 2017-02-08
class Solution {
 public:
  vector<string> findWords(vector<string>& words) {
    string rows[] = {
      "qwertyuiopQWERTYUIOP",
      "asdfghjklASDFGHJKL",
      "zxcvbnmZXCVBNM"
    };
    vector<string> result;
    for (const string& word : words)
      if (any_of(rows, rows + 3, [this, word](const string& row) {
        return contains(row, word);
      })) result.push_back(word);
    return result;
  }

 private:
  bool contains(const string& row, const string& word) const {
    return all_of(word.begin(), word.end(), [row](char c) {
      return row.find(c) != string::npos;
    });
  }
};
