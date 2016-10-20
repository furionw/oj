#include <vector>
#include <map>
#include <queue>
#include <algorithm>

using namespace std;

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
