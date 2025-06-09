// 2025-06-05
class RangeModule {
 public:
  void addRange(int left, int right) {
    --right;
    // cout << "addRange: " << left << ", " << right << endl;
    ranges_[left] = right;
    for (auto it = ranges_.begin(), prev = ranges_.begin(); it != ranges_.end();) {
      if (prev == it) {
        ++it;
        continue;
      }
      if (prev->second + 1 < it->first) {
        ++prev;
        ++it;
        continue;
      }
      // prev->second + 1 >= it->first
      if (prev->second <= it->second) {
        prev->second = it->second;
        // cout << "foo2\n";
        // cout << "ranges_.size() = " << ranges_.size() << endl;
        auto next = it;
        ++next;
        ranges_.erase(it);
        it = next;
        continue;
      }
      // cout << "foo3\n";
      // prev->second > it->second
      auto next = it;
      ++next;
      ranges_.erase(it);
      it = next;
    }
    // inspect();
  }
    
  bool queryRange(int left, int right) {
    --right;
    // cout << "queryRange: " << left << ", " << right << endl;
    auto it = lower_bound(ranges_.rbegin(), ranges_.rend(), left,
        [](const auto& elem, int v) {
          return elem.first > v;
        });

    // inspect();
    return it != ranges_.rend() && it->second >= right;
  }
   
  void removeRange(int left, int right) {
    --right;
    // cout << "removeRange: " << left << ", " << right << endl;  
    for (auto it = ranges_.begin(); it != ranges_.end();) {
      if (it->second < left || it->first > right) {
        ++it;
        continue;
      }
      // it->second >= left && it->first <= right
      // There is an overlap.
      if (it->first < left) {
        if (it->second <= right) {
          it->second = left - 1;
          ++it;
          continue;
        }
        // it->second > right
        ranges_.emplace(right + 1, it->second);
        it->second = left - 1;
        break;
      }
      // left <= it->first <= right
      if (it->second <= right) {
        auto next = it;
        ++next;
        ranges_.erase(it);
        it = next;
        continue;
      // it->second > right
      } else {
        ranges_.emplace(right + 1, it->second);
        ranges_.erase(it);
        break;
      }
    }
    // inspect();
  }

 private:
  void inspect() {
    cout << "inspect\n";
    for (auto [k, v]: ranges_) {
      cout << k << ", " << v << endl;
    }
    cout << '\n';
  }

  // left close, right close
  map<int, int> ranges_;
};
