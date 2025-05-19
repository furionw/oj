// Date: 2025-05-18
class Dir {
 public:
  vector<string> ls(string path) {
    if (path.empty()) {
      return ls();
    }

    auto idx = path.find('/');
    auto token = path.substr(0, idx);
    if (idx == string::npos) {
      if (dirs.contains(token)) {
        return dirs[token].ls("");
      } else {
        return {token};
      }
    } else {
      return dirs[token].ls(path.substr(idx + 1));
    }
  }
  
  void mkdir(string path) {
    if (path.empty()) {
      throw std::runtime_error("path should not be empty");
    }
    auto idx = path.find('/');
    auto token = path.substr(0, idx);
    auto& child = dirs[token];
    if (idx != string::npos) {
      child.mkdir(path.substr(idx + 1));
    }
  }
  
  void addContentToFile(string filePath, string content) {
    auto idx = filePath.find('/');
    auto token = filePath.substr(0, idx);
    if (idx == string::npos) {
      files[token] += content;
    } else {
      dirs[token].addContentToFile(filePath.substr(idx + 1), content);
    }
  }
  
  string readContentFromFile(string filePath) {
    auto idx = filePath.find('/');
    auto token = filePath.substr(0, idx);
    if (idx == string::npos) {
      return files[token];
    } else {
      return dirs[token].readContentFromFile(filePath.substr(idx + 1));
    }
  }

  void print() {
    cout << "print\n";
    for (const auto& path : ls()) {
      cout << path << endl;
    }
  }

 private:
  vector<string> ls() {
    // cout << "gan\n";
    vector<string> result;
    auto i = dirs.begin();
    auto j = files.begin();
    while (i != dirs.end() && j != files.end()) {
      if (i->first < j->first) {
        result.push_back(i->first);
        ++i;
      } else {
        result.push_back(j->first);
        ++j;
      }
    }
    for (; i != dirs.end(); ++i) {
      result.push_back(i->first);
    }
    for (; j != files.end(); ++j) {
      result.push_back(j->first);
    }
    return result;
  }

  map<string, Dir> dirs;
  map<string, string> files;
};


class FileSystem {
 public:
  FileSystem() {}
  
  vector<string> ls(string path) {
    return dir.ls(path.substr(1));
  }
  
  void mkdir(string path) {
    // cout << "mkdir\n";
    dir.mkdir(path.substr(1));
    // dir.print();
  }
  
  void addContentToFile(string filePath, string content) {
    // cout << "addContentToFile\n";
    dir.addContentToFile(filePath.substr(1), content);
    // dir.print();
  }
  
  string readContentFromFile(string filePath) {
    return dir.readContentFromFile(filePath.substr(1));
  }

 private:
  Dir dir;
};
