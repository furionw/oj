#include <vector>
#include <queue>
#include <algorithm>
#include <map>

using namespace std;

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