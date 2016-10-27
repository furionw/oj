#include <iostream>
#include <vector>

using namespace std;

int main() {
  int N;
  cin >> N;
  int increment_cnt = 0;
  vector<int> nums(N);
  cin >> nums[0];
  for (int i = 1; i < N; ++ i) {
    cin >> nums[i];
    increment_cnt = nums[i] > nums[i-1]? increment_cnt + 1: 1;
  }
  for (int i = 0; i < N - increment_cnt; ++ i) {
    cout << nums[i];
    if (i != N - increment_cnt - 1)
      cout << " ";
  }
  if (increment_cnt == N)
    cout << 1 << '\n';
}
