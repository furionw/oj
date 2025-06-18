// 2025-06-17
class Dir {
 public:
  bool createPath(string path, int value) {
    auto pos = path.find('/', 1 /*pos*/);
    if (pos == string::npos) {
      auto it = files_.find(path.substr(1));
      if (it == files_.end()) {
        string p = path.substr(1);
        files_[p] = value;
        dirs_[p] = dirs_[p];
        return true;
      } else {
        // pre-existing. do not override
        return false;
      }
    } else {
      // "/abc/ddd"
      // pos = 4, len = 3
      auto it = dirs_.find(path.substr(1, pos - 1));
      if (it == dirs_.end()) {
        // parent path doesn't exist
        return false;
      } else {
        return it->second.createPath(path.substr(pos), value);
      }
    }
  }
    
  int get(string path) const {
    auto pos = path.find('/', 1 /*pos*/);
    if (pos == string::npos) {
      auto it = files_.find(path.substr(1));
      return it != files_.end() ? it->second : -1;
    } else {
      // "/abc/ddd"
      // pos = 4, len = 3
      auto it = dirs_.find(path.substr(1, pos - 1));
      return it != dirs_.end() ? it->second.get(path.substr(pos)) : -1;
    }
  }

 private:
  unordered_map<string, Dir> dirs_;
  unordered_map<string, int> files_;
};

class FileSystem {
 public:
  bool createPath(string path, int value) {
    return dir_.createPath(path, value);
  }
    
  int get(string path) {
    return dir_.get(path);
  }
  
 private:
  Dir dir_;
};
