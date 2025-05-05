// 2025-05-01
// Method 1
class Solution {
 public:
  bool canChange(string start, string target) {
    string str1, str2;
    queue<int> startLs, startRs, targetLs, targetRs;
    for (size_t i = 0; i < start.size(); ++i) {
      if (start[i] == 'L') {
        str1 += start[i];
        startLs.push(i);
      } else if (start[i] == 'R') {
        str1 += start[i];
        startRs.push(i);
      }

      if (target[i] == 'L') {
        str2 += target[i];
        targetLs.push(i);
      } else if (target[i] == 'R') {
        str2 += target[i];
        targetRs.push(i);
      }
    }

    if (str1 != str2) {
      return false;
    }

    for (; !targetLs.empty(); targetLs.pop(), startLs.pop()) {
      if (startLs.front() < targetLs.front()) {
        return false;
      }
    }

    for (; !targetRs.empty(); targetRs.pop(), startRs.pop()) {
      if (startRs.front() > targetRs.front()) {
        return false;
      }
    }

    return true;
  }
};

// Method 2
class Solution {
 public:
  bool canChange(string start, string target) {
    int n = start.size();
    int i = 0, j = 0;

    for (; i <= n && j <= n; ++i, ++j) {
      for (; i < n && start[i] == '_'; ++i) {}
      for (; j < n && target[j] == '_'; ++j) {}
      
      if (i == n || j == n) {
        break;
      }

      if ((start[i] != target[j])
          || (start[i] == 'L' && i < j)
          || (start[i] == 'R' && i > j)
      ) {
        return false;
      }
    }

    return i == n && j == n;
  }
};
