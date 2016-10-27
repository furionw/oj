#include <unordered_set>
#include <iostream>
#include <cstdint>
#include <cmath>

using namespace std;

long long gcd(long long a, long long b) {
  if (b == 0)
    return a;
  else
    return gcd(b, a % b);
}

int main() {
  int N, M;
  cin >> N >> M;
  unordered_set<long long> ns, ms;
  uint64_t n = sqrt(N), m = sqrt(M);
  for (uint64_t i = 1; i <= n; ++ i)
    if (N % i == 0) {
      ns.insert(i);
      if (ns.find(N / i) == ns.end())
        ns.insert(N / i);
    }
  uint64_t match = 0;
  for (uint64_t i = 1; i <= m; ++ i)
    if (M % i == 0) {
      ms.insert(i);
      match += (ns.find(i)!=ns.end()? 1: 0);
      if (ms.find(M / i) == ms.end()) {
        ms.insert(M / i);
        match += (ns.find(M/i)!=ns.end()? 1: 0);
      }
    }
  uint64_t divisor = gcd(ns.size() * ms.size(), match);
  cout << ns.size()*ms.size()/divisor << " " << match/divisor << '\n';
}
