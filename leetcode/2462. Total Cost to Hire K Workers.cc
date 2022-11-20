// Date: 2022-11-19
// Method 3
// min heap -- priority_queue<int, vector<int>, greater<int>>
// 195 ms (faster than 93%), 73 MB (less than 53%)
class Solution {
 public:
  long long totalCost(vector<int>& costs, int k, int candidates) {
    priority_queue<int, vector<int>, greater<int>> leftCosts, rightCosts;
    int left = 0;
    int right = costs.size()  - 1;
    for (; left < candidates && left < costs.size(); ++left) {
      leftCosts.push(costs[left]);
    }
    for (; left <= right && costs.size() - right <= candidates; --right) {
      rightCosts.push(costs[right]);
    }
    long long res = 0;
    for (; k > 0; --k) {
      if (leftCosts.empty()) {
        res += delta(rightCosts);
      } else if (rightCosts.empty()) {
        res += delta(leftCosts);
      } else if (rightCosts.top() < leftCosts.top()) {
        res += delta(rightCosts);
        if (left <= right) {
          rightCosts.push(costs[right]);
          --right;
        }
      } else {
        res += delta(leftCosts);
        if (left <= right) {
          leftCosts.push(costs[left]);
          ++left;
        }
      }
    }
    return res;
  }
  
 private:
  int delta(priority_queue<int, vector<int>, greater<int>>& costs) {
    int cost = costs.top();
    costs.pop();
    return cost;
  }
};

// Method 2
// multiset<int>
// 393 ms, 112 MB
class Solution {
 public:
  long long totalCost(vector<int>& costs, int k, int candidates) {
    multiset<int> leftCosts, rightCosts;
    int left = 0;
    int right = costs.size()  - 1;
    for (; left < candidates && left < costs.size(); ++left) {
      leftCosts.insert(costs[left]);
    }
    for (; left <= right && costs.size() - right <= candidates; --right) {
      rightCosts.insert(costs[right]);
    }
    long long res = 0;
    for (; k > 0; --k) {
      if (leftCosts.empty()) {
        res += delta(rightCosts);
      } else if (rightCosts.empty()) {
        res += delta(leftCosts);
      } else if (*rightCosts.begin() < *leftCosts.begin()) {
        res += delta(rightCosts);
        if (left <= right) {
          rightCosts.insert(costs[right]);
          --right;
        }
      } else {
        res += delta(leftCosts);
        if (left <= right) {
          leftCosts.insert(costs[left]);
          ++left;
        }
      }
    }
    return res;
  }
  
 private:
  int delta(multiset<int>& costs) {
    int cost = *costs.begin();
    costs.erase(costs.begin());
    return cost;
  }
};

// Method 1
// map<int, queue<int>>
// 826 ms, 311 MB
class Solution {
 public:
  long long totalCost(vector<int>& costs, int k, int candidates) {
    map<int, queue<int>> leftCostToIdxs, rightCostToIdxs;
    int left = 0;
    int right = costs.size()  - 1;
    for (; left < candidates && left < costs.size(); ++left) {
      leftCostToIdxs[costs[left]].push(left);
    }
    for (; left <= right && costs.size() - right <= candidates; --right) {
      rightCostToIdxs[costs[right]].push(right);
    }
    long long res = 0;
    for (; k > 0; --k) {
      if (leftCostToIdxs.empty()) {
        res += delta(rightCostToIdxs);
      } else if (rightCostToIdxs.empty()) {
        res += delta(leftCostToIdxs);
      } else if (rightCostToIdxs.begin()->first < leftCostToIdxs.begin()->first) {
        res += delta(rightCostToIdxs);
        if (left <= right) {
          rightCostToIdxs[costs[right]].push(right);
          --right;
        }
      } else {
        res += delta(leftCostToIdxs);
        if (left <= right) {
          leftCostToIdxs[costs[left]].push(left);
          ++left;
        }
      }
    }
    return res;
  }
  
 private:
  int delta(map<int, queue<int>>& costToIdxs) {
    int cost = costToIdxs.begin()->first;
    auto it = costToIdxs.begin();
    it->second.pop();
    if (it->second.empty()) {
      costToIdxs.erase(it);
    }
    return cost;
  }
};
