// 2025-06-17
struct Job {
  int s;
  int e;
  int p;

  bool operator<(const Job& other) const {
    return s != other.s ? s < other.s : e < other.e;
  }
};

class Solution {
 public:
  int jobScheduling(vector<int>& startTime, vector<int>& endTime,
      vector<int>& profit) {
    int n = profit.size();
    vector<Job> jobs;
    for (int i = 0; i < n; ++i) {
      jobs.push_back(Job {
        .s = startTime[i],
        .e = endTime[i],
        .p = profit[i]
      });
    }
    sort(jobs.begin(), jobs.end());
    vector<int> dp(n, 0);
    dp.back() = jobs.back().p;
    for (int i = n - 2; i >= 0; --i) {
      dp[i] = max(dp[i + 1], jobs[i].p);
      auto it = lower_bound(jobs.begin() + i + 1, jobs.end(), jobs[i].e,
          [](const Job& job, int end) {
            return job.s < end;
          });
      dp[i] = it == jobs.end()
          ? dp[i]
          : max(dp[i], jobs[i].p + dp[it - jobs.begin()]);
    }
    return dp[0];
  }
};
