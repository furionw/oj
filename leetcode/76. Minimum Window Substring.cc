// Copyright 2017 Qi Wang
// Date: 2017-11-12
class Solution {
 public:
  string minWindow(string s, string t) {
    if (s.size() < t.size() || t.empty()) return "";
    unordered_map<char, int> char_to_cnt_map;
    for (char c : t) ++char_to_cnt_map[c];
    int min_len = INT_MAX, min_begin = -1;
    for (int i = 0, char_to_match = t.size(), begin = 0; i < s.size(); ++i) {
      if (char_to_cnt_map[s[i]] > 0) --char_to_match;
      --char_to_cnt_map[s[i]];
      if (char_to_match == 0) {
        while (char_to_cnt_map[s[begin]] < 0) {
          ++char_to_cnt_map[s[begin++]];
        }
        if (i - begin + 1 < min_len) {
          min_begin = begin;
          min_len = i - begin + 1;
        }
      }
    }
    return min_begin != -1 ? s.substr(min_begin, min_len) : "";
  }
};

// Date: 2017-11-04
// Case 1: "", ""
// Case 2: "abcdccb", "bcc"
//   - i == 4 -> begin = 1, min_len = 4, min_begin = 1
//   - i == 6 -> begin = 4, min_len = 3, min_begin = 4
// Case 3: "bba", "ab"
// Case 4: "ADOBECODEBANC" "ABC"
// Please note that the solution on 2017-07-14 is more concise. But still,
// congratualtions!
class Solution {
 public:
  string minWindow(string s, string t) {
    if (s.size() < t.size() || t.empty()) return "";
    unordered_map<char, int> char_to_cnt_map;
    for (char c : t) ++char_to_cnt_map[c];
    int char_to_match = t.size();
    int begin = 0;
    int min_len = INT_MAX, min_begin = -1;
    for (int i = 0; i < s.size(); ++i) {
      if (char_to_cnt_map.count(s[i])) {
        // You cannot write code like
        // if (char_to_match > 0) --char_to_match;
        // Or your solution will fail in the case 3.
        if (--char_to_cnt_map[s[i]] >= 0) --char_to_match;
        if (char_to_match == 0) {
          // Please note that you cannot write code like:
          // while (char_to_cnt_map.count(s[begin]) == 0 ||
          //        char_to_cnt_map[s[begin]] < 0) {
          //   ++char_to_cnt_map[s[begin++]];
          // }
          // Or your solution it will fail in the case 4, because the new K/V
          // pair would be inserted into the map when the while condition is
          // evaluated.
          for (; true; ++begin) {
            if (char_to_cnt_map.count(s[begin]) == 0) continue;
            if (char_to_cnt_map[s[begin]] == 0) {
              break;
            } else {
              ++char_to_cnt_map[s[begin]];
            }
          }
          if (i - begin + 1 < min_len) {
            min_len = i - begin + 1;
            min_begin = begin;
          }
        }
      }
    }
    return min_begin != -1 ? s.substr(min_begin, min_len) : "";
  }
};

// Date: 2017-07-14
// Refer to the previous solution
class Solution {
 public:
  string minWindow(string s, string t) {
    size_t pos = 0, len = INT_MAX;
    vector<int> need_find(127, 0), has_found(127, 0);
    for (char c : t) {
      ++need_find[c];
    }
    for (int cnt = t.size(), begin = 0, end = 0;
        end < s.size(); ++end) {
      if (0 != cnt && has_found[s[end]] < need_find[s[end]]) --cnt;
      ++has_found[s[end]];
      if (0 == cnt) {
        for (; has_found[s[begin]] > need_find[s[begin]]; ++begin) {
          --has_found[s[begin]];
        }
        if (end - begin + 1 < len) {
          pos = begin;
          len = end - begin + 1;
        }
      }
    }
    return len != INT_MAX ? s.substr(pos, len) : "";
  }
};

// Revisited on: 2017-03-09
class Solution 
{
public:
    string minWindow(string S, string T) 
    {
      int has_found[256] = {0};
      int need_find[256] = {0};
      size_t min_length = INT_MAX;
      size_t min_begin = 0;

      for (size_t i = 0; i < T.size(); ++ i)
      {
        ++ need_find[T[i]];
      }
      for (size_t cnt = T.size(), begin=0, end=0; end < S.size(); ++ end)
      {
        ++ has_found[S[end]];
        if (has_found[S[end]] <= need_find[S[end]])
        {
          -- cnt;
        }
        if (cnt == 0)
        {
          for ( ; has_found[S[begin]] > need_find[S[begin]]; ++ begin)
          {
            -- has_found[S[begin]];
          }
          if (end-begin+1 < min_length)
          {
            min_length = end-begin+1;
            min_begin = begin;
          }
        }
      }

      return min_length==INT_MAX? "": S.substr(min_begin, min_length);
    }
};
