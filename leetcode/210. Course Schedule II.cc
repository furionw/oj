// Copyright 2017 Qi Wang
// Date: 2017-11-11
// Note that the solution on 2016-10-24 using queue is more concise.
class Solution {
 public:
  vector<int> findOrder(int num_courses,
                        vector<pair<int, int>>& prerequisites)  {
    vector<int> ins(num_courses, 0);
    vector<list<int>> edges(num_courses);
    for (const auto& p : prerequisites) {
      edges[p.second].push_back(p.first);
      ++ins[p.first];
    }
    vector<int> result;
    for (int i = 0; i < num_courses; ++i) {
      int u = -1;
      for (int j = 0; j < num_courses; ++j) {
        if (ins[j] == 0) {
          u = j;
          break;
        }
      }
      if (u == -1) break;
      ins[u] = -1;
      result.push_back(u);
      for (int v : edges[u]) {
        --ins[v];
      }
    }
    return result.size() == num_courses ? result : vector<int>();
  }
};

// Date: 2017-08-03
// Note that the solution on 2016-10-24 using queue is more concise.
class Solution {
 public:
  vector<int> findOrder(int numCourses,
                        vector<pair<int, int>>& prerequisites) {
    if (numCourses == 0) return {};
    vector<list<int>> edges(numCourses);
    vector<int> in_degree(numCourses, 0);
    for (const auto& p : prerequisites) {
      if (find(edges[p.first].begin(), edges[p.first].end(), p.second)
          != edges[p.first].end()) {
        return {};
      } else {
        ++in_degree[p.first];
        edges[p.second].push_back(p.first);
      }
    }
    vector<int> result;
    while (true) {
      int u = -1;
      for (int i = 0; i < numCourses; ++i) {
        if (in_degree[i] == 0) {
          in_degree[i] = -1;
          u = i;
          break;
        }
      }
      if (u == -1) break;
      result.push_back(u);
      for (int v : edges[u]) {
        --in_degree[v];
      }
    }
    return result.size() == numCourses ? result : vector<int>();
  }
};

// Date: 2016-10-24
class Solution {
 public:
  vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
    vector<list<int>> map(numCourses);
    vector<int> inDegree(numCourses, 0);
    for (auto& p : prerequisites) {
      map[p.first].push_back(p.second);
      ++inDegree[p.second];
    }
    queue<int> zeroInDegreeQ;
    for (int i = 0; i < numCourses; ++i)
      if (inDegree[i] == 0) zeroInDegreeQ.push(i);
    vector<int> res;
    while (!zeroInDegreeQ.empty()) {
      int u = zeroInDegreeQ.front();
      zeroInDegreeQ.pop();
      res.insert(res.begin(), u);
      for (int v : map[u])
        if (--inDegree[v] == 0) zeroInDegreeQ.push(v);
    }
    return res.size() == numCourses ? res : vector<int>();
  }
};

// Date: 2015-08
class Solution 
{
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) 
    {
      // [0, {1, 2, 3}], means after finishing #0, you "might" be able to take #1, #2, #3
      // That is, you must finish #0, before trying to take #1, #2, #3
      map<int, vector<int>> course_chain;
      vector<int> in_degree(numCourses, 0);
      queue<int> q;
      vector<int> ret;

      for (auto p: prerequisites)
      {    
        // self-loop, return empty vector.          
        if (p.first == p.second)
        {
          return vector<int>();
        }
        // no duplicate edges input
        if (find(course_chain[p.second].begin(), course_chain[p.second].end(), p.first) 
          == course_chain[p.second].end())
        {
          course_chain[p.second].push_back(p.first);
          ++ in_degree[p.first];
        }
      }
      for (size_t i = 0; i < numCourses; ++ i)
      {
        if (in_degree[i] == 0)
        {
          q.push(i);
        }
      }
      for (; !q.empty(); q.pop())
      {
        int pre_course = q.front();
        ret.push_back(pre_course);
        for (auto it = course_chain[pre_course].begin(); it != course_chain[pre_course].end(); ++ it)
        {
          -- in_degree[*it];
          if (in_degree[*it] == 0)
          {
            q.push(*it);
          }
        }
      }

      return ret.size()==numCourses? ret: vector<int>();
    }
};
