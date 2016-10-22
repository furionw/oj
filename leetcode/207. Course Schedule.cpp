// Copyright 2016 Qi Wang
// Date: 2016-10-22
class Solution {
 public:
  bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
    vector<list<int>> map(numCourses);
    vector<int> inDegree(numCourses, 0);
    for (auto& p : prerequisites) {
      map[p.first].push_back(p.second);
      ++inDegree[p.second];
    }
    queue<int> zeroInDegreeQ;
    for (int i = 0; i < numCourses; ++i)
      if (inDegree[i] == 0) zeroInDegreeQ.push(i);
    while (!zeroInDegreeQ.empty()) {
      int u = zeroInDegreeQ.front();
      zeroInDegreeQ.pop();
      for (int v : map[u])
        if (--inDegree[v] == 0) zeroInDegreeQ.push(v);
    }
    return all_of(inDegree.begin(), inDegree.end(), [](int degree) {
      return degree == 0;
    });
  }
};

// Date: 2015-08
class Solution
{
public:
	bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites)
	{
		vector<vector<bool>> map(numCourses, vector<bool>(numCourses, false));
		vector<int> in_degree(numCourses, 0);
		for_each(prerequisites.begin(), prerequisites.end(),
			[&map, &in_degree](pair<int,int> p)
			{
				if (map[p.first][p.second] == false)
				{
					map[p.first][p.second] = true;
					++ in_degree[p.second];
				}
			});
		queue<int> q;
		for (int id = 0; id < numCourses; ++ id)
		{
			if (in_degree[id] == 0)
			{
				q.push(id);
			}
		}
		while (!q.empty())
		{
			int course = q.front();
			q.pop();
			for (int id = 0; id < numCourses; ++ id)
			{
				if (map[course][id] == true)
				{
					-- in_degree[id];
					if (in_degree[id] == 0)
					{
						q.push(id);
					}
				}
			}
		}
		return all_of(in_degree.begin(), in_degree.end(), [](int in) -> bool
		{
			return in == 0;
		});
	}
};
