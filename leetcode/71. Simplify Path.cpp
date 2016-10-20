#include <string>
#include <vector>

using namespace std;

class Solution 
{
public:
    string simplifyPath(string path) 
    {
        vector<string> dir;
        string ret;

        dir.push_back("/");
        for (size_t begin, end=0; ; )
        {
            for (begin=end+1 ; begin<path.size() && path[begin]=='/'; ++ begin) {}
            if (begin >= path.size())
            {
                break;
            }
        	end = path.find('/', begin);
            end = end!=string::npos? end: path.size();
        	auto cur = path.substr(begin, end-begin);
        	if (cur!="." && cur!="..")
        	{
        		dir.push_back(cur + "/");
        	} else if (cur==".." && dir.size()>1)
        	{
        		dir.pop_back();
        	}
        }
        for (size_t i = 0; i < dir.size(); ++ i)
        {
        	if (i==0 || i!=dir.size()-1)
        	{
        		ret += dir[i];
        	} else
        	{
        		ret += dir[i].substr(0, dir[i].size()-1); // no slash
        	}
        }

        return ret;
    }
};