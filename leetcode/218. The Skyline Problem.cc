// 2025-05-28
class Solution {
 public:
  vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
    vector<vector<int>> edges;
    for (int i = 0; i < buildings.size(); ++i) {
      edges.push_back({buildings[i][0], i});
      edges.push_back({buildings[i][1], i});
    }
    sort(edges.begin(), edges.end());
    vector<vector<int>> result;
    priority_queue<pair<int, int>> pq;

    for (int i = 0; i < edges.size(); ++i) {
      const auto& e = edges[i];
      const auto& b = buildings[e[1]];
      int x = e[0];
      int h = b[2];
      pq.push({h, b[1]});

      for (; i + 1 < edges.size() && edges[i + 1][0] == x; ++i) {
        const auto& b2 = buildings[edges[i + 1][1]];
        pq.push({b2[2], b2[1]});
        // Note: can do something like this instead for efficiency. (see previous solution)
        // if (x == b2[0]) {
        //   pq.push({b2[2], b2[1]});
        // }
      }

      for (; !pq.empty() && pq.top().second <= x; pq.pop()) {}
      
      if (pq.empty()) {
        result.push_back({x, 0});
      } else if (result.empty() || pq.top().first != result.back()[1]) {
        result.push_back({x, pq.top().first});
      }
    }
    return result;
  }
};

// 2025-05-06
// Refer to the Editorial
class Solution {
 public:
  vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
    vector<pair<int, int>> edges;
    for (int i = 0; i < buildings.size(); ++i) {
      edges.push_back({buildings[i][0], i});
      edges.push_back({buildings[i][1], i});
    }
    sort(edges.begin(), edges.end());

    vector<vector<int>> result;
    priority_queue<pair<int, int>> pq;
    for (int i = 0; i < edges.size(); ) {
      const auto& e = edges[i];
      int curX = e.first;
      for (; i < edges.size() && edges[i].first == curX; ++i) {
        int b = edges[i].second;
        const auto& building = buildings[b];
        if (curX == building[0]) {
          pq.push({building[2], building[1]});
        }
      }
      for (; !pq.empty() && pq.top().second <= curX; pq.pop()) {}
      if (pq.empty()) {
        result.push_back({curX, 0});
      } else if (result.empty() || pq.top().first != result.back()[1]) {
        result.push_back({curX, pq.top().first});
      }
    }

    return result;
  }
};


// Date: 2017-11-09
// Refer to the soluton on 2017-09-07
class Solution {
 public:
  vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
    vector<pair<int, int>> idx_and_height_vt;
    for (const auto& row : buildings) {
      idx_and_height_vt.emplace_back(row[0], -row[2]);
      idx_and_height_vt.emplace_back(row[1], row[2]);
    }
    sort(idx_and_height_vt.begin(), idx_and_height_vt.end());
    vector<pair<int, int>> result;
    multiset<int> heights;
    heights.insert(0);
    int prev = 0;
    for (const auto& p : idx_and_height_vt) {
      if (p.second < 0) {
        heights.insert(-p.second);
      } else {
        heights.erase(heights.find(p.second));
      }
      if (*heights.rbegin() != prev) {
        result.emplace_back(p.first, *heights.rbegin());
        prev = *heights.rbegin();
      }
    }
    return result;
  }
};

// Date: 2017-09-07
class Solution {
 public:
  vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
    vector<pair<int, int>> heights;
    for (const auto& building : buildings) {
      // In my strategy, the 'start' pair, rather than the 'end' pair, should
      // contain a negative '.second', or the sort won't work. That's because
      // we want to access the 'start' pair first for the pairs sharing the
      // same '.first' location.
      heights.emplace_back(building[0], -building[2]);
      heights.emplace_back(building[1], building[2]);
    }
    sort(heights.begin(), heights.end());
    multiset<int> height_set;
    height_set.insert(0);
    int prev = 0;
    vector<pair<int, int>> result;
    for (const auto& height : heights) {
      if (height.second < 0) {
        height_set.insert(-height.second);
      } else {
        height_set.erase(height_set.find(height.second));
      }
      if (*height_set.rbegin() != prev) {
        result.emplace_back(height.first, *height_set.rbegin());
        prev = *height_set.rbegin();
      }
    }
    return result;
  }
};

// Date: 2017-08-16
// Refer to: http://blog.csdn.net/jeanphorn/article/details/46638289
class Solution {
 public:
  vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
    vector<pair<int, int>> heights;
    for (const auto& building : buildings) {
      // In my strategy, this pair should contains negative sencond number,
      // or the sort won't work
      heights.emplace_back(building[0], -building[2]);
      heights.emplace_back(building[1], building[2]);
    }
    sort(heights.begin(), heights.end());
    multiset<int> height_set;
    height_set.insert(0);
    int prev = 0;
    vector<pair<int, int>> result;
    for (const auto& height : heights) {
      if (height.second < 0) {
        height_set.insert(-height.second);
      } else {
        // Use iterator rather than key here, or all the pairs contains the
        // same key will be removed.
        height_set.erase(height_set.find(height.second));
      }
      if (*height_set.rbegin() != prev) {
        result.emplace_back(height.first, *height_set.rbegin());
        prev = *height_set.rbegin();
      }
    }
    return result;
  }
};
