// Copyright 2017 Qi Wang
// Date: 2017-08-03
class Solution {
 public:
  vector<string> fullJustify(vector<string>& words, int maxWidth) {
    vector<string> result;
    for (int i = 0; i < words.size();) {
      int cnt = 1, len = words[i].size();
      for (++i; i < words.size() && len + 1 + words[i].size() <= maxWidth;
          ++i) {
        ++cnt;
        len += 1 + words[i].size();
      }
      int tot_len = accumulate(words.begin() + i - cnt, words.begin() + i, 0,
                               [](int acc, const string& word) {
                                 return acc + word.size();
                               });
      if (cnt == 1) {
        result.push_back(words[i - 1] + string(maxWidth - tot_len, ' '));
      } else if (i != words.size()) {
        int every = (maxWidth - tot_len) / (cnt - 1);
        int extra = (maxWidth - tot_len) % (cnt - 1);
        string line = words[i - cnt];
        for (int j = i - cnt + 1; j < i; ++j)
          line += string(every + (extra-- > 0), ' ') + words[j];
        result.push_back(line);
      // last line
      } else {
        string line = words[i - cnt];
        for (int j = i - cnt + 1; j < i; ++j)
          line += string(1, ' ') + words[j];
        line += string(maxWidth - line.size(), ' ');
        result.push_back(line);
      }
    }
    return result;
  }
};

// Date: 2014-08
class Solution 
{
public:
  vector<string> fullJustify(vector<string> &words, int L) 
  {
    vector<string> ret;

    for (size_t i = 0; i < words.size(); )
    {
      size_t begin=i, length=words[i].size();
      for (++ i; i < words.size(); )
      {
        if (length+1+words[i].size() <= L)
        {
          length = length + 1 + words[i].size();
          ++ i;
        } else
        {
          break;
        }
      }
      int words_cnt = i - begin;
      length = L;
      for (int j = begin; j < i; ++ j)
      {
        length -= words[j].size();
      }

      if (i - begin == 1)
      {
        ret.push_back(words[begin] + string(L-words[begin].size(), ' '));       
      } else if (i == words.size())
      {
        string line;
        for (int j = begin; j < i; ++ j)
        {
          line += words[j];
          line += " ";
        }
        line += string(L-line.size(), ' ');
        ret.push_back(line);
      } else
      {
        int every = length / (i-begin-1);
        int extra = length % (i-begin-1);
        string line;
        for (int j = begin; j < i; ++ j)
        {
          line += words[j];
          if (j != i-1)
          {
            if (j-begin < extra)
            {
              line += string(every+1, ' ');
            } else
            {
              line += string(every, ' ');
            }
          }
        }
        ret.push_back(line);
      }
    }

    return ret;
  }
};
