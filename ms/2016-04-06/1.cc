#include <iostream>
#include <vector>
#include <numeric>
#include <cmath>

using namespace std;

void gao() {
  int n, p, w, h;
  cin >> n >> p >> w >> h;
  vector<int> characters(n);
  for (size_t i = 0; i < characters.size(); ++ i)
    cin >> characters[i];
  for (int s = min(w, h); s >= 1; -- s) {
    int lines = p * (h / s);
    auto acc = [s, w](int sum, int c) { return sum + ceil(1.0 * c / (w / s)); };
    if (accumulate(characters.begin(), characters.end(), 0, acc) <= lines) {
      cout << s << '\n';
      return ;
    }
  }
}

int main() {
  int tasks;
  cin >> tasks;
  while (tasks --)
    gao();
}
