#include <map>
#include <queue>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <string>
#include <iostream>

using namespace std;

class Solution
{
public:
	vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) 
	{
		unordered_map<string, vector<string>> paths;
//		paths
		unordered_map<string, int> dis;
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
//		dis.clear();

		if (dis.find(end) == dis.end())
		{
			return vector<vector<string>>();
		} else
		{
			vector<string> path;
			GeneratePath(paths, path, end);
			return result_;
		}
	}

private:
	void GeneratePath(unordered_map<string, vector<string>> &paths,vector<string>& path, const string& word)
	{
		if (paths[word].size() == 0)
		{
			path.push_back(word);
			vector<string> curPath = path;
			reverse(curPath.begin(), curPath.end());
			result_.push_back(curPath);
			path.pop_back();
			return;
		}
		path.push_back(word);
		for (auto iter = paths[word].begin(); iter != paths[word].end(); ++iter)
			GeneratePath(paths, path, *iter);
		path.pop_back();
	}
	//	map<string, vector<string>> paths;
	vector<vector<string>> result_;
};

int main()
{
	Solution a;
	unordered_set<string> dict;
/*	dict.insert("hot");
	dict.insert("dot");
	dict.insert("dog");
	dict.insert("lot");
	dict.insert("log");
	auto result = a.findLadders("hit", "cog", dict);*/

/*	dict.insert("hot");
	dict.insert("dog");
	auto result = a.findLadders("hot", "dog", dict);*/

	dict.insert("a");
	dict.insert("b");
	dict.insert("c");
	auto result = a.findLadders("a", "c", dict);

	return 0;
}