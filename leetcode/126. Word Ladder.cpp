#include <map>
#include <queue>

using namespace std;

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