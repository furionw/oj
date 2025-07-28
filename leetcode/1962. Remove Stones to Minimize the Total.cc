// 2025-07-27
class Solution {
 public:
  int minStoneSum(vector<int>& piles, int k) {
    priority_queue<int> pq;
    for (int p : piles) {
      pq.push(p);
    }

    for (int i = 0; i < k; ++i) {
      int p = pq.top();
      pq.pop();
      pq.push(p - p / 2);
    }

    int result = 0;
    for (; !pq.empty(); pq.pop()) {
      result += pq.top();
    }
    return result;
  }
};
