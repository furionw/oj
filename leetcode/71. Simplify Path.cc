// Copyright 2017 Qi Wang
// Date: 2017-11-09
// Case 1: "/" -> "/"
// Case 2: "//" -> "/"
// Case 3: "/a/.../b/.." -> "/a/..."
class Solution {
 public:
  string simplifyPath(string path) {
    if (path.empty()) return "";
    list<string> dirs;
    for (int i = 0; i < path.size(); ++i) {
      if (path[i] == '/') continue;
      int dot_cnt = 0;
      for (; i + dot_cnt < path.size() && path[i + dot_cnt] == '.';
           ++dot_cnt) {}
      if (dot_cnt == 1 &&
          (i + dot_cnt == path.size() || path[i + dot_cnt] == '/')) {
        i += dot_cnt;
      } else if (dot_cnt == 2 &&
          (i + dot_cnt == path.size() || path[i + dot_cnt] == '/')) {
        if (!dirs.empty()) dirs.pop_back();
        i += dot_cnt;
      } else {
        int next_pos = path.find('/', i);
        dirs.push_back(path.substr(i, next_pos - i));
        if (next_pos == string::npos) {
          break;
        } else {
          i = next_pos;
        }
      }
    }
    if (dirs.empty()) return "/";
    return accumulate(dirs.begin(), dirs.end(), string(""),
                      [](const string& path, const string& dir) {
                        return path + string(1, '/') + dir;
                      });
  }
};

// Date: 2017-07-26
class Solution {
 public:
  string simplifyPath(string path) {
    list<string> dirs;
    for (int pos = 0; pos < path.size(); ++pos) {
      if (path[pos] == '/') continue;
      size_t next_pos = path.find('/', pos);
      string dir = path.substr(pos, next_pos - pos);
      if (count(dir.begin(), dir.end(), '.') == dir.size()) {
        if (dir.size() == 2 && !dirs.empty()) {
          dirs.pop_back();
        } else if (dir.size() > 2) {
          dirs.push_back(dir);
        }
      } else {
        dirs.push_back(dir);
      }
      if (next_pos == string::npos) {
        break; 
      } else {
        pos = next_pos;
      }
    }
    return GetPath(dirs);
  }

 private:
  string GetPath(const list<string>& dirs) const {
    if (dirs.empty()) return "/";
    string path;
    for (const auto& dir : dirs) {
      path += '/';
      path += dir;
    }
    return path;
  }
};

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