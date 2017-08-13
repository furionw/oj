// Copyright 2017 Qi Wang
// Date: 2017-08-12
class Solution {
 public:
  bool isPossible(vector<int>& nums) {
    int cnt = 0;
    // num -> seq
    unordered_map<int, priority_queue<int, vector<int>, greater<int>>> record;
    for (int num : nums) {
      if (record.find(num - 1) == record.end()) {
        record[num].push(1);
      } else {
        int seq_cnt = record[num - 1].top();
        record[num - 1].pop();
        if (record[num - 1].empty()) {
          record.erase(num - 1);
        }
        record[num].push(seq_cnt + 1);
      }
    }
    for (auto& p : record) {
      auto& pq = p.second;
      while (!pq.empty()) {
        // cout << pq.top() << endl;
        if (pq.top() < 3) return false;
        pq.pop();
      }
    }
    return true;
  }
};
