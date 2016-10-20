#include <map>
#include <queue>
#include <vector>
#include <unordered_set>
#include <string>

using namespace std;

class Solution 
{
public:
	vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) 
	{
		map<string, vector<vector<string>>> paths;
		paths[start].push_back(vector<string>(1, start));
		map<string, int> dis;
		dis[start] = 1;
		vector<string> vt[2];

		while (!vt[0].empty() || !vt[1].empty())
		{
			if ()
			{
				
			}
		}

		while (q[0].empty()==false || q[1].empty()==false)
		{
			if (q[0].empty() == true)
			{
				
			}
			string cur = q[0].front();
			for (size_t i = 0; i < cur.size(); ++ i)
			{
				for (int j = 0; j < 26; ++ j)
				{
					string tmp = cur;
					tmp[i] = 'a' + j;
					if (dict.find(tmp) != dict.end()
						&& (dis.find(tmp) == dis.end() || dis[cur] + 1 == dis[tmp]) )
					{
						for (auto it = paths[cur].begin(); it != paths[cur].end(); ++ it)
						{
							vector<string> path(*it);
							path.push_back(tmp);
							paths[tmp].push_back(path);
						}
						dis[tmp] = dis[cur] + 1;
						q[1].push(tmp);
					}
				}
			}
			q[0].pop();
		}

		return paths[end];
	}
};