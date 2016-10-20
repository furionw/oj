#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <list>
#include <unordered_map>

using namespace std;

struct Student {
  string id;
  int curTime;
  list<pair<int, int>> offices;

  bool operator <(const Student& other) {
    if (curTime != other.curTime) {
      return 
    }
  }
};

struct Office {
  bool ocupy = false;
  int curTime = 0;
};

int main() {
  int n, m, k;
  cin >> n >> m >> k;
  vector<Student> students(n);
  vector<Office> offices(m);
  for (int i = 0; i < n; ++i) {
    int officeCnt;
    cin >> students[i].id >> students[i].curTime >> officeCnt;
    for (int j = 0; j < officeCnt; ++j) {
      int officeId, processTime;
      cin >> officeId >> processTime;
      students[i].offices.emplace_back(officeId - 1, processTime);
    }
  }
  // more elegant lambda?
  while (any_of(students.begin(), students.end(), [](const Student& s) { return s.officeVisited != s.offices.size();})) {
    
  }
}
