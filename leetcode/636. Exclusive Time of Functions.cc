// Copyright 2017 Qi Wang
// Date: 2017-11-06
// Case 1: ["0:start:0", "1:start:2", "1:end:5", "0:end:6"]
class Solution {
 public:
  vector<int> exclusiveTime(int n, vector<string>& logs) {
    vector<int> result(n, 0);
    if (logs.empty()) return result;
    int prev_time, id;
    char s[6];
    // I think it's better to initialize 'prev_time' here than what I
    // did on 2017-08-17
    sscanf(logs.front().data(), "%d:%[^:]:%d", &id, s, &prev_time);
    stack<int> ids;
    ids.push(id);
    for (int i = 1; i < logs.size(); ++i) {
      int cur_time;
      sscanf(logs[i].data(), "%d:%[^:]:%d", &id, s, &cur_time);
      if (s[0] == 's') {
        if (!ids.empty()) result[ids.top()] += cur_time - prev_time;
        ids.push(id);
        prev_time = cur_time;
      } else {
        result[ids.top()] += cur_time - prev_time + 1;
        ids.pop();
        prev_time = cur_time + 1;
      }
    }
    return result;
  }
};

// Date: 2017-08-17
class Solution {
 public:
  vector<int> exclusiveTime(int n, vector<string>& logs) {
    vector<int> result(n, 0);
    stack<int> ids;
    int prev_time = 0;
    for (const string& log : logs) {
      char s[6];
      int id, t;
      sscanf(log.data(), "%d:%[^:]:%d", &id, s, &t);
      if (s[0] == 's') {
        if (!ids.empty()) {
          result[ids.top()] += t - prev_time;
        }
        prev_time = t;
        ids.push(id);
      } else {
        result[id] += t - prev_time + 1;
        prev_time = t + 1;
        ids.pop();
      }
    }
    return result;
  }
};
 
// Date: 2017-08-06
// Refer to the previous solution...
class Solution {
 public:
  vector<int> exclusiveTime(int n, vector<string>& logs) {
    vector<int> result(n, 0);
    stack<int> ids;
    int last_time;
    for (const string& log : logs) {
      int id, time;
      char str[6];
      sscanf(log.data(), "%d:%[^:]:%d", &id, str, &time);
      if (str[0] == 's') {
        if (!ids.empty())
          result[ids.top()] += time - last_time;
        ids.push(id);
      } else {
        result[ids.top()] += ++time - last_time;
        ids.pop();
      }
      last_time = time;
    }
    return result;
  }
};
 
// Date: 2017-07-15
// Method 2
// Refer to Fangrui Song's solution
class Solution {
 public:
  vector<int> exclusiveTime(int n, vector<string>& logs) {
    vector<int> result(n, 0);
    stack<int> ids;
    int last_time = 0;
    for (const string& log : logs) {
      char chars[6];
      int id, time;
      // http://en.cppreference.com/w/cpp/io/c/fscanf
      sscanf(log.data(), "%d:%[^:]:%d", &id, chars, &time);
      if ('e' == chars[0]) {
        result[ids.top()] += ++time - last_time;
        ids.pop();
      } else {
        if (!ids.empty()) result[ids.top()] += time - last_time;
        ids.push(id);
      }
      last_time = time;
    }
    return result;
  }
};

// Date: 2017-07-15
// Method 1
class Solution {
 public:
  vector<int> exclusiveTime(int n, vector<string>& logs) {
    vector<int> result(n);
    for (int idx = 0; idx < logs.size();) {
      auto info = Parse(logs[idx++]);
      F(logs, &idx, info.func_id, info.time, &result);
    }
    return result;
  }

 private:
  struct Info {
    int func_id;
    bool is_start;
    int time;
  };

  int F(const vector<string>& logs, int* idx,
      int func_id, int start_time, vector<int>* result) const {
    int sub_time = 0;
    while (true) {
      auto info = Parse(logs[*idx]);
      *idx = *idx + 1;  // ?
      if (!info.is_start) {
        int period = info.time - start_time + 1 - sub_time;
        (*result)[func_id] += period;
        // printf("idx = %d, sub_time = %d, period = %d, result = %d\n", *idx - 1, sub_time, period, (*result)[func_id]);
        // printf("func_id = %d, start = %d, end = %d\n", func_id, start_time, info.time);
        return info.time - start_time + 1;
      } else {
        // printf("inc\n");
        sub_time += F(logs, idx, info.func_id, info.time, result);
      }
    }
    return -1;
  }

  Info Parse(const string& str) const {
    size_t pos = str.find(':');
    size_t pos2 = str.find(':', pos + 1);
    return {
      stoi(str.substr(0, pos)),
      str[pos + 1] == 's',
      stoi(str.substr(pos2 + 1))
    };
  }
};

// Fangrui Song's solution
class Solution {
 public:
  vector<int> exclusiveTime(int n, vector<string>& logs) {
    vector<int> a(n), b;
    int l, t, id;
    for (auto log: logs) {
      char st[9];
      sscanf(log.c_str(), "%d:%[^:]:%d", &id, st, &t);
      if (st[0] == 'e') {
        a[b.back()] += ++t-l;
        b.pop_back();
      } else {
        if (b.size()) a[b.back()] += t-l;
        b.push_back(id);
      }
      l = t;
    }
    return a;
  }
};
