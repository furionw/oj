// Copyright 2016 Qi Wang
// BFS
// Date: 2016-11-20
class Solution {
 public:
  int ladderLength(string beginWord, string endWord,
      unordered_set<string>& wordList) {
    // boost up the trivial case
    if (beginWord == endWord) return 2;
    queue<pair<string, int>> q;
    q.emplace(beginWord, 2);
    while (!q.empty()) {
      string word = q.front().first;
      int dis = q.front().second;
      q.pop();
      for (size_t i = 0; i < word.size(); ++i) {
        for (char c = 'a'; c <= 'z'; ++c)
          if (c != word[i]) {
            swap(word[i], c);
            if (word == endWord) return dis;
            if (wordList.find(word) != wordList.end()) {
              q.emplace(word, dis + 1);
              wordList.erase(word);
            }
            swap(word[i], c);
          }
      }
    }
    return 0;
  }
};

// Date: 2015-02
class Solution 
{
public:
    int ladderLength(string start, string end, unordered_set<string> &dict) 
    {
        map<string, int> dis;
        queue<string> q;        
        dis[start] = 1;
        q.push(start);

        dict.insert(end);
        while (q.empty() == false)
        {
            string cur = q.front();
            for (size_t i = 0; i < cur.size(); ++ i)
            {
                for (int j = 0; j < 26; ++ j)
                {
                    string tmp = cur;
                    tmp[i] = 'a' + j;
                    if (dict.find(tmp)!=dict.end()
                        && dis.find(tmp)==dis.end())
                    {
                        dis[tmp] = dis[cur] + 1;
                        q.push(tmp);
                    }
                }
            }
            q.pop();
        }

        return dis[end];
    }
};