// Copyright 2016 Qi Wang
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
