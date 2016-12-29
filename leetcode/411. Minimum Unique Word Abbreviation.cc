// Copyright 2016 Qi Wang
// Date: 2016-12-28
// Method 3: Method 2 re-implementation
class Solution {
 public:
  string minAbbreviation(string target, vector<string>& dictionary) {
    vector<int> diffs;
    for (auto& word : dictionary) {
      if (word.size() != target.size()) continue;
      int diff = 0;
      for (size_t i = 0; i < target.size(); ++i)
        if (word[i] != target[i])
          diff |= 1 << i;
      diffs.push_back(diff);
    }
    if (diffs.empty()) return to_string(target.size());
    int candidate = 0;
    for (int diff : diffs) candidate |= diff;
    auto lenToMask = getMask(candidate, target.size());
    for (auto& p : lenToMask)
      for (int mask : p.second)
        if (all_of(diffs.begin(), diffs.end(), [this, mask](int diff) {
          return (mask & diff) != 0;
        })) return generateAbbr(target, mask);
    return "";  // not found!
  }

 private:
  map<int, vector<int>> getMask(int candidate, size_t sz) const {
    map<int, vector<int>> res;
    getMask(candidate, 0, sz, 0, 0, 0, res);
    return res;
  }

  void getMask(int candidate, size_t idx, size_t sz, int cur,
      int len, int zeroCnt, map<int, vector<int>>& res) const {
    if (idx == sz) {
      if (cur != 0) res[len].push_back(cur);
    } else if ((candidate & (1 << idx)) != 0) {
      getMask(candidate, idx + 1, sz, cur,
          len + (zeroCnt == 0), zeroCnt + 1, res);
      getMask(candidate, idx + 1, sz, cur | (1 << idx),
          len + 1, 0, res);
    } else {
      getMask(candidate, idx + 1, sz, cur,
          len + (zeroCnt == 0), zeroCnt + 1, res);
    }
  }

  string generateAbbr(const string& word, int mask) const {
    string abbr;
    for (size_t i = 0; i < word.size();) {
      if ((mask & (1 << i)) != 0) {
        abbr += word[i++];
      // (mask & (1 << i)) == 0
      } else {
        int len = 1;
        for (; i + len < word.size() && (mask & (1 << i + len)) == 0; ++len) {}
        abbr += to_string(len);
        i += len;
      }
    }
    return abbr;
  }
};

// Date: 2016-12-28
// Method 2: Refer to the top solutions
class Solution {
 public:
  string minAbbreviation(string target, vector<string>& dictionary) {
    vector<int> diffs;
    for (auto& word : dictionary) {
      if (word.size() != target.size()) continue;
      int diff = 0;
      for (size_t i = 0; i < target.size(); ++i)
        if (word[i] != target[i])
          diff |= 1 << i;
      diffs.push_back(diff);
    }
    if (diffs.empty()) return to_string(target.size());
    int candidate = 0;
    for (int diff : diffs) candidate |= diff;
    vector<int> candidates;
    for (size_t i = 0; i < target.size(); ++i)
      if ((candidate & (1 << i)) != 0)
        candidates.push_back(1 << i);
    auto masks = getMask(candidates);
    map<int, vector<int>> lenToMask;
    for (int mask : masks)
      lenToMask[maskToLen(mask, target.size())].push_back(mask);
    masks = vector<int>();  // clear masks, reallocate its memory
    for (auto& p : lenToMask) {
      for (int mask : p.second)
        if (all_of(diffs.begin(), diffs.end(), [this, mask](int diff) {
          return (mask & diff) != 0;
        })) return generateAbbr(target, mask);
    }
    
    return "";  // not found!
  }

 private:
  vector<int> getMask(const vector<int>& candidates) const {
    vector<int> res;
    getMask(candidates, 0, 0, res);
    return res;
  }

  void getMask(const vector<int>& candidates, size_t idx, int cur,
      vector<int>& res) const {
    if (idx == candidates.size()) {
      res.push_back(cur);
    } else {
      getMask(candidates, idx + 1, cur, res);
      getMask(candidates, idx + 1, cur | candidates[idx], res);
    }
  }

  int maskToLen(int mask, size_t sz) const {
    int res = 0;
    for (size_t i = 0; i < sz; ++res) {
      if ((mask & (1 << i)) != 0) {
        ++i;
      } else {
        int len = 1;
        for (; i + len < sz && (mask & (1 << i + len)) == 0; ++len) {}
        i += len;
      }
    }
    return res;
  }

  string generateAbbr(const string& word, int mask) const {
    string abbr;
    for (size_t i = 0; i < word.size();) {
      if ((mask & (1 << i)) != 0) {
        abbr += word[i++];
      // (mask & (1 << i)) == 0
      } else {
        int len = 1;
        for (; i + len < word.size() && (mask & (1 << i + len)) == 0; ++len) {}
        abbr += to_string(len);
        i += len;
      }
    }
    return abbr;
  }
};

// Date: 2016-12-28
// Method 1: MLE when input "usaandchinaarefriends", []
class Solution {
 public:
  string minAbbreviation(string target, vector<string>& dict) {
    auto abbrs = generateAbbreviations(target);
    map<int, vector<string>> lenToAbbrs;
    for (auto& abbr : abbrs)
      lenToAbbrs[getLen(abbr)].push_back(move(abbr));
    for (auto& p : lenToAbbrs)
      for (auto& abbr : p.second)
        if (all_of(dict.begin(), dict.end(), [this, abbr](const string& word) {
          return !isAbbr(word, abbr);
        })) return abbr;
    return "";  // comfort the compiler
  }

 private:
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
      if (isDigit(abbr[0])) {
        size_t len = 1;
        for(; len < abbr.size() && isDigit(abbr[len]); ++len) {}
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

  int getLen(const string& abbr) const {
    int len = 0;
    for (size_t i = 0; i < abbr.size(); ++len) {
      if (isDigit(abbr[i])) {
        for (; i < abbr.size() && isDigit(abbr[i]); ++i) {}
        continue;
      }
      ++i;
    }
    return len;
  }
  
  bool isAbbr(const string& word, const string& abbr) const {
    size_t i = 0, j = 0;
    while (i < word.size() && j < abbr.size()) {
      if (isDigit(abbr[j])) {
        size_t len = 1;
        for (; j + len < abbr.size() && isDigit(abbr[j + len]); ++len) {}
        i += stoi(abbr.substr(j, len));
        j += len;
      } else if (word[i] != abbr[j]) {
        return false;
      } else {
        ++i, ++j;
      }
    }
    return i == word.size() && j == abbr.size();
  }

  bool isDigit(char c) const { return '0' <= c && c <= '9'; }
};
