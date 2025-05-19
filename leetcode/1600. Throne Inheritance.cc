// 2025-05-18
class ThroneInheritance {
 public:
  ThroneInheritance(string name): name_(name) {}
  
  void birth(string parentName, string childName) {
    childrenMap_[parentName].push_back(childName);
  }
  
  void death(string name) {
    deaths_.insert(name);
  }
  
  vector<string> getInheritanceOrder() {
    vector<string> result;
    getInheritanceOrder(name_, result);
    return result;
  }

 private:
  void getInheritanceOrder(const string& name, vector<string>& result) const {
    if (!deaths_.contains(name)) {
      result.push_back(name);
    }
    auto it = childrenMap_.find(name);
    if (it == childrenMap_.end()) {
      return;
    }
    for (const auto& child : it->second) {
      getInheritanceOrder(child, result);
    }
  }

  string name_;
  unordered_map<string, vector<string>> childrenMap_;
  unordered_set<string> deaths_;
};

// 2025-05-18
// TLE
class ThroneInheritance {
 public:
  ThroneInheritance(string name): name_(name) {}
  
  void birth(string parentName, string childName) {
    if (name_ == parentName) {
      children_.emplace_back(childName);
      return;
    }
    for (auto& child : children_) {
      child.birth(parentName, childName);
    }
  }
  
  void death(string name) {
    if (name_ == name) {
      dead_ = true;
      return;
    }
    for (auto& child : children_) {
      child.death(name);
    }
  }
  
  vector<string> getInheritanceOrder() {
    vector<string> result;
    getInheritanceOrder(result);
    return result;
  }

 private:
  void getInheritanceOrder(vector<string>& result) const {
    if (!dead_) {
      result.push_back(name_);
    }
    for (const auto& child: children_) {
      child.getInheritanceOrder(result);
    }
  }

  string name_;
  bool dead_ = false;
  vector<ThroneInheritance> children_;
};
