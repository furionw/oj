// Copyright 2017 Qi Wang
// Date: 2017-10-12
/*
// Employee info
class Employee {
public:
    // It's the unique ID of each node.
    // unique id of this employee
    int id;
    // the importance value of this employee
    int importance;
    // the id of direct subordinates
    vector<int> subordinates;
};
*/
class Solution {
 public:
  int getImportance(vector<Employee*> employees, int id) {
    unordered_map<int, Employee*> id_to_employee_map;
    for (auto* employee : employees) {
      id_to_employee_map[employee->id] = employee;
    }
    return GetImportance(&id_to_employee_map, id);
  }
 
 private:
  int GetImportance(unordered_map<int, Employee*>* id_to_employee_map,
                    int id) const {
    const auto* employee = (*id_to_employee_map)[id];
    int importance = employee->importance;
    for (int subordinate : employee->subordinates) {
      importance += GetImportance(id_to_employee_map, subordinate);
    }
    return importance;
  }
};
