// Date: 2022-12-9
class Solution {
 public:
  long long dividePlayers(vector<int>& skill) {
    int n = skill.size();
    int tot = accumulate(skill.begin(), skill.end(), 0);
    if (tot % (n / 2) != 0) {
      return -1;
    }
    int sum = tot / (n / 2);
    sort(skill.begin(), skill.end());
    long long res = 0;
    for (int i = 0; i < n / 2; ++i) {
      if (skill[i] + skill[n - i - 1] != sum) {
        return -1;
      }
      res += 1L * skill[i] * skill[n - i - 1];
    }
    return res;
  }
};

// Date: 2022-12-3
class Solution {
 public:
  long long dividePlayers(vector<int>& skill) {
    int n = skill.size();
    int tot = accumulate(skill.begin(), skill.end(), 0);
    if (tot % (n / 2) != 0) {
      return -1;
    }
    unordered_map<int, int> sToCnt;
    for (int s : skill) {
      ++sToCnt[s];
    }
    int sum = tot / (n / 2);
    long long res = 0;
    for (const auto& [s, cnt] : sToCnt) {
      if (cnt == 0) {
        continue;
      }
      int counter = sum - s;
      if (s == counter) {
        if (cnt % 2 != 0) {
          return -1;
        } else {
          res += 1L * s * s * cnt / 2;
        }
      } else if (sToCnt[counter] != cnt) {
        return -1;
      } else {
        sToCnt[counter] = 0;
        res += 1L * s * counter * cnt;
      }
      // maybe not needed
      sToCnt[s] = 0;
    }
    return res;
  }
};
