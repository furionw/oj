// Date: 2022-11-21
class Solution {
 public:
  long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
    int n = roads.size() + 1;
    vector<vector<int>> g(n, vector<int>());
    for (const auto& r : roads) {
      g[r[0]].push_back(r[1]);
      g[r[1]].push_back(r[0]);
    }
    vector<bool> seen(n, false);
    return f(seats, g, seen, 0).first;
  }
  
 private:
  /**
   * @return a pair of fuel and reps
   */
  std::pair<long long, int> f(
      int seats, const vector<vector<int>>& g,
      vector<bool>& seen, int v) {
    seen[v] = true;
    long long fuel = 0;
    int reps = 1;
    for (auto u : g[v]) {
      if (seen[u]) {
        continue;
      }
      auto [subFuel, subReps] = f(seats, g, seen, u);
      fuel += subFuel;
      reps += subReps;
    }
    return {fuel + (v == 0 ? 0 : ceil(1. * reps / seats)), reps};
  }
};
