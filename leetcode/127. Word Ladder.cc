// Copyright 2017 Qi Wang
// Date: 2017-11-10
// Refer to the previous solution on 2017-07-30.
class Solution {
 public:
  int ladderLength(string beginWord, string endWord, vector<string>& words) {
    if (find(words.begin(), words.end(), endWord) == words.end())
      return 0;
    vector<int> dist(words.size(), INT_MAX);
    vector<bool> vi(words.size(), false);
    for (int i = 0; i < words.size(); ++i) {
      if (Transformable(beginWord, words[i])) {
        dist[i] = 2;
      }
    }
    while (true) {
      int idx = -1, min_dist = INT_MAX;
      for (int i = 0; i < dist.size(); ++i) {
        if (!vi[i] && dist[i] < min_dist) {
          idx = i;
          min_dist = dist[i];
        }
      }
      if (idx == -1) break;
      if (words[idx] == endWord) return min_dist;
      vi[idx] = true;
      for (int i = 0; i < dist.size(); ++i) {
        if (Transformable(words[idx], words[i]) && min_dist + 1 < dist[i]) {
          dist[i] = min_dist + 1;
        } 
      }
    }
    return 0;
  }
 
 private:
  bool Transformable(const string& lhs, const string& rhs) const {
    int diff = 0;
    for (int i = 0; i < lhs.size() && diff < 2; ++i) {
      diff += lhs[i] != rhs[i];
    }
    return diff == 1;
  }
};

// Date: 2017-07-30
class Solution {
 public:
  int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    if (find(wordList.begin(), wordList.end(), endWord) == wordList.end()) {
      return 0;
    }
    vector<int> dist(wordList.size(), INT_MAX);
    vector<bool> vi(wordList.size(), false);
    for (int i = 0; i < wordList.size(); ++i) {
      if (Transformable(beginWord, wordList[i])) {
        dist[i] = 2;
      }
    }
    while (true) {
      int u = -1, min_dist = INT_MAX;
      for (int i = 0; i < wordList.size(); ++i) {
        if (!vi[i] && dist[i] < min_dist) {
          min_dist = dist[i];
          u = i;
        }
      }
      if (u == -1) break;
      if (wordList[u] == endWord) return dist[u];
      vi[u] = true;
      for (int i = 0; i < wordList.size(); ++i) {
        if (Transformable(wordList[u], wordList[i])) {
          dist[i] = min(dist[i], dist[u] + 1);
        }
      }
    }
    return 0;
  }

 private:
  bool Transformable(const string& u, const string& v) const {
    int cnt = 0;
    for (int i = 0; i < u.size(); ++i)
      cnt += u[i] != v[i];
    return cnt == 1;
  }
};

// BFS
// Date: 2016-11-20
class Solution {
 public:
  int ladderLength(string beginWord, string endWord,
      unordered_set<string>& wordList) {
    // boost up the trivial case
    if (beginWord == endWord) return 2;
    queue<pair<string, int>> q;
    q.emplace(beginWord, 1);
    while (!q.empty()) {
      string word = q.front().first;
      int dis = q.front().second;
      q.pop();
      for (size_t i = 0; i < word.size(); ++i) {
        for (char c = 'a'; c <= 'z'; ++c)
          if (c != word[i]) {
            swap(word[i], c);
            if (word == endWord) return dis + 1;
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