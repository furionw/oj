// 2025-05-04
// Method 2
// Refer to the Editorial
class MyCalendar {
 public:
  bool book(int startTime, int endTime) {
    auto it = events.lower_bound(startTime);

    if (it != events.end() && it->first < endTime) {
      return false;
    }

    if (it != events.begin()) {
      --it;
      if (startTime < it->second) {
        return false;
      }
    }
    
    events[startTime] = endTime;
    return true;
  }

 private:
  map<int, int> events;
};


// Method 1
class MyCalendar {
 public:
  bool book(int startTime, int endTime) {
    if (events.empty()) {
      events[startTime] = endTime;
      return true;
    }

    auto lb = events.lower_bound(endTime);
    bool booked = false;
    if (lb == events.end()) {
      // all events have start time smaller than `endTime`
      auto it = events.rbegin();
      booked = it->second <= startTime;
    } else {
      // lb points to an event, of which event.startTime >= `endTime`
      if (lb == events.begin()) {
        booked = true;
      } else {
        --lb;
        booked = lb->second <= startTime;
      }
    }
    if (booked) {
      events[startTime] = endTime;
    }
    return booked;
  }

 private:
  map<int, int> events;
};
