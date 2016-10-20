#include <queue>
#include <algorithm>
#include <string>
#include <queue>
#include <iostream>

using namespace std;

struct Student {
  Student(int idx) : idx(idx) {}

  inline bool operator < (const Student& other) const {
    if (time != other.time) {
      return time > other.time;
    } else {
      return id > other.id;
    }
  }

  int idx;
  string id;
  int time;
  queue<pair<int, int>> offices;
};

struct Office {
  priority_queue<Student> students;
  int time = 0;
};

vector<Office>::iterator findOffice(const vector<Office>& offices) {
  return min_element(offices.begin(), offices.end(), [](const Office& office) {
    
  });
}

int main() {
  // init
  int n, m, k;
  cin >> n >> m >> k;
  vector<int> finishedTime(n);
  vector<Office> offices(m);
  for (int i = 0; i < n; ++i) {
    // cout << "i: " << i << endl;
    Student student(i);
    cin >> student.id >> student.time;
    // cout << student.id << ", " << student.time << endl;
    int officeCnt;
    cin >> officeCnt;
    // cout << officeCnt << endl;
    for (int j = 0; j < officeCnt; ++j) {
      int officeId, processTime;
      cin >> officeId >> processTime;
      // cout << "officeId and time: " << officeId << ", " << processTime << endl;
      student.offices.emplace(officeId - 1, processTime);
    }
    offices[student.offices.front().first].students.push(student);
  }
  // begin
  for (auto it = findNonEmptyOffice(offices); it != offices.end();
      it = findNonEmptyOffice(offices)) {
    auto student = it->top();
    // cout << student.id << ", " << student.time << endl;
    it->pop();
    // increment time
    student.time += student.offices.front().second + k;
    student.offices.pop();
    if (student.offices.empty()) {
      // done
      finishedTime[student.idx] = student.time;
    } else {
      // enter the next office
      offices[student.offices.front().first].push(student);
    }
  }
  for (int time : finishedTime) cout << time << endl;
}
