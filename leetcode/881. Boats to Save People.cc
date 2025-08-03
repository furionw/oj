// 2025-07-29
// Method 2: refer to the Editorial
class Solution {
 public:
  int numRescueBoats(vector<int>& people, int limit) {
    sort(people.begin(), people.end());
    int result = 0;
    for (int i = 0, j = people.size() - 1; i <= j;) {
      if (i == j) {
        return result + 1;
      } else if (people[i] + people[j] <= limit) {
        ++result;
        ++i;
        --j;
      } else {
        ++result;
        --j;
      }
    }
    return result;
  }
};

// 2025-07-29
class Solution {
 public:
  int numRescueBoats(vector<int>& people, int limit) {
    multiset<int, greater<int>> s;
    for (int p : people) {
      s.insert(p);
    }

    int result = 0;
    while (s.size() >= 2) {
      ++result;
      int remain = limit - *s.begin();
      s.erase(s.begin());
      auto it = s.lower_bound(remain);
      if (it == s.end()) {
        continue;
      }
      s.erase(it);
    }
    return result + s.size();
  }
};
