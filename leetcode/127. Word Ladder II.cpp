#include <map>
#include <queue>
#include <vector>
#include <unordered_set>
#include <string>
#include <iostream>

using namespace std;

class Solution
{
public:
	vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) 
	{
		queue<string> q;

		q.push(start);
		dis[start] = 1;
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

int main()
{
	Solution a;
	unordered_set<string> dict;
	dict.insert("hot");
	dict.insert("dot");
	dict.insert("dog");
	dict.insert("lot");
	dict.insert("log");
	auto result = a.findLadders("hit", "cog", dict);

	return 0;
}