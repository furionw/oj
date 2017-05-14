// Copyright 2017 Qi Wang
// Date: 2017-05-13
#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

struct Rule {
  Rule(int a, int b, int u) : a(a), b(b), u(u) {}
  int a, b, u;
};

int n, k, m;
int result = 0;
vector<Rule> rules;
unordered_set<int> med1, med2;

void Bar(int idx, int cur, unordered_set<int>& med, unordered_set<int>& other);

void Foo(int idx, int cur) {
  if (idx == rules.size()) return;
  Bar(idx, cur, med1, med2);
  Bar(idx, cur, med2, med1);
  Foo(idx + 1, cur);
}

void Bar(int idx, int cur, unordered_set<int>& med, unordered_set<int>& other) {
  if (0 == med.count(rules[idx].a) && 0 == med.count(rules[idx].b)
      && 0 == other.count(rules[idx].a) && 0 == other.count(rules[idx].b)
      && med.size() + 2 <= k) {
    med.insert(rules[idx].a);
    med.insert(rules[idx].b);
    result = max(result, cur += rules[idx].u);
    Foo(idx + 1, cur);
    cur -= rules[idx].u;
    med.erase(rules[idx].a);
    med.erase(rules[idx].b);
  }
  if (0 == med.count(rules[idx].a) && 1 == med.count(rules[idx].b)
      && 0 == other.count(rules[idx].a) && med.size() + 1 <= k) {
    med.insert(rules[idx].a);
    result = max(result, cur += rules[idx].u);
    Foo(idx + 1, cur);
    cur -= rules[idx].u;
    med.erase(rules[idx].a);
  }
  if (1 == med.count(rules[idx].a) && 0 == med.count(rules[idx].b)
      && 0 == other.count(rules[idx].b) && med.size() + 1 <= k) {
    med.insert(rules[idx].b);
    result = max(result, cur += rules[idx].u);
    Foo(idx + 1, cur);
    cur -= rules[idx].u;
    med.erase(rules[idx].b);
  }
  if (1 == med.count(rules[idx].a) && 1 == med.count(rules[idx].b)) {
    result = max(result, cur += rules[idx].u);
    Foo(idx + 1, cur);
  }
}

int main() {
  cin >> n >> k >> m;
  while (m--) {
    int a, b, u;
    cin >> a >> b >> u;
    rules.emplace_back(a, b, u);
  }
  Foo(0, 0);
  cout << result << endl;
}
