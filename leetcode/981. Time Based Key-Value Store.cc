// 2025-04-27
class TimeMap {
 public:
  void set(string key, string value, int timestamp) {
    keyToValues[key][timestamp] = value;
  }
    
  string get(string key, int timestamp) {
    auto valuesIt = keyToValues.find(key);
    if (valuesIt == keyToValues.end()) {
      return "";
    }
    const auto& values = valuesIt->second;
    auto it = values.lower_bound(timestamp);
    if (it == values.end()) {
      return values.rbegin()->second;
    } else if (it->first == timestamp) {
      return it->second;
    } else if (it == values.begin()) {
      return "";
    } else {
      return (--it)->second;
    }
  }

 private:
  map<string, map<int, string>> keyToValues;
};
