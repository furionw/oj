// Copyright 2017 Qi Wang
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

// The test cases do not cover the situation where endWord is not in the
// wordList, which is like the sample
//   beginWord = "hit"
//   endWord = "cog"
//   wordList = ["hot","dot","dog","lot","log"]
// In such case, my submission in 2015-02 should have come up with a wrong answer
//   - https://leetcode.com/submissions/detail/20841336/

// Note that it seems unordered_set's count() is faster than its find()

// Method 2
// Time: beats 74.70% cpp solutions with 255ms in the best run
// Refer to: https://leetcode.com/submissions/detail/20841336/
class Solution {
 public:
  vector<vector<string>> findLadders(string begin, string end,
      unordered_set<string> &dict) {
    unordered_map<string, list<string>> preTbl;
    unordered_set<string> words[2];
    int flag = 0;
    words[flag].insert(begin);
    while (!words[flag].empty() && words[flag].find(end) == words[flag].end()) {
      int preFlag = flag;
      flag = !flag;
      words[flag].clear();
      for (auto it = words[preFlag].begin(); it != words[preFlag].end(); ++it)
        dict.erase(*it);
      for (auto it = words[preFlag].begin(); it != words[preFlag].end(); ++it) {
        for (size_t i = 0; i < it->size(); ++i) {
          // define "next" here, instead of defining it inside 'a' to 'z' loop
          string next = *it;
          for (char c = 'a'; c <= 'z'; ++c) {
            next[i] = c;
            // A new vertex could be reached via the previous layer's vertices
            if (next == end || dict.count(next)) {
              preTbl[next].push_back(*it);
              words[flag].insert(next);
            }
          }
        }
      }
    }
    vector<string> path;
    // "end" is reachable
    if (words[flag].find(end) != words[flag].end())
      generatePaths(preTbl, end, path);
    return paths;
  }

 private:
  void generatePaths(unordered_map<string, list<string>>& preTbl,
      const string& cur, vector<string>& path) {
    if (preTbl[cur].empty()) {
      auto ans = path;
      ans.push_back(cur);
      reverse(ans.begin(), ans.end());
      paths.push_back(ans);
    } else {
      path.push_back(cur);
      for (auto& pre : preTbl[cur])
        generatePaths(preTbl, pre, path);
      path.pop_back();
    }
  }

  vector<vector<string>> paths;
};

// Method 1
// Date: 2016-11-21
class Solution {
 public:
  vector<vector<string>> findLadders(string begin, string end,
      unordered_set<string> &wordList) {
    unordered_map<string, int> distTbl;
    unordered_map<string, list<string>> preTbl;
    distTbl[begin] = 0;
    queue<string> q;
    q.push(begin);
    while (!q.empty()) {
      string cur = q.front();
      // Introducing this erasing mechanism can really boost up the procedure
      wordList.erase(cur);
      q.pop();
      for (size_t i = 0; i < cur.size(); ++i) {
        // define "next" here, instead of defining it inside 'a' to 'z' loop
        string next = cur;
        for (char c = 'a'; c <= 'z'; ++c) {
          // identical word
          if (c == cur[i]) continue;
          next[i] = c;
          // There is no such new word in the wordList
          if (next != end && wordList.find(next) == wordList.end()) continue;
          // This is the brand new word haven't been discovered before
          if (distTbl.find(next) == distTbl.end()) {
            distTbl[next] = distTbl[cur] + 1;
            preTbl[next].push_back(cur);
            q.push(next);
          // A word has been discovered before but with the same distance
          } else if (distTbl[next] == distTbl[cur] + 1) {
            preTbl[next].push_back(cur);
          }
        }
      }
    }
    return distTbl.find(end) == distTbl.end()
        ? vector<vector<string>>()
        : generatePaths(preTbl, end);
  }

 private:
  vector<vector<string>> generatePaths(unordered_map<string, list<string>>& preTbl,
      const string& cur) {
    vector<vector<string>> res;
    for (const auto& pre : preTbl[cur]) {
      auto prePaths = move(generatePaths(preTbl, pre));
      for (auto& prePath : prePaths)
        res.push_back(move(prePath));
    }
    for (auto& path : res) path.push_back(cur);
    return res.empty()
        ? vector<vector<string>>(1, vector<string>(1, cur))
        : res;
  }
};

// Date: 2015-02
class Solution
{
public:
  vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) 
  {
    dis[start] = 1;
    queue<string> q;        
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
          if (dict.find(tmp) != dict.end())
          {
            if (dis.find(tmp) == dis.end())
            {
              dis[tmp] = dis[cur] + 1;
              paths[tmp].push_back(cur);
              q.push(tmp);
            } else if (dis[cur] + 1 == dis[tmp])
            {
              paths[tmp].push_back(cur);
            }
          }

        }
      }
      dict.erase(cur);
      q.pop();
    }

    return recurse(end);
  }

private:
  vector<vector<string>> recurse(const string& cur)
  {
    vector<vector<string>> ret;
    for (auto it = paths[cur].begin(); it != paths[cur].end(); ++ it)
    {
      vector<vector<string>> tmp(recurse(*it));
      for (auto itt = tmp.begin(); itt != tmp.end(); ++ itt)
      {
        itt->push_back( cur );
        ret.push_back(*itt);
      }
    }
    if (dis[cur] == 1)
    {
      ret.push_back( vector<string>(1, cur) ); // cur==begin
    }
    return ret;
  }
  map<string, int> dis;
  map<string, vector<string>> paths;
};
