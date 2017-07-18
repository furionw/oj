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
