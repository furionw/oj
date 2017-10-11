#ifndef _TIMER_H
#define _TIMER_H

#include <cassert>
#include <chrono>
#include <iostream>
#include <string>
#include <stack>
#include <typeinfo>

class timer {
  using high_resolution_clock = std::chrono::high_resolution_clock;
  struct event;

 public:
  inline static void start(const std::string& prompt,
      std::ostream& os = std::cout) {
    assert(!prompt.empty());
    _events.push(event(prompt));
    // output
    os << prompt << " start." << std::endl;		
  }

  template <typename T>
  inline static void stop(std::ostream& os = std::cout) {
    assert(!_events.empty());
    auto event = _events.top();
    _events.pop();
    // output
    os << event._name << " stop: "
        << std::chrono::duration_cast<T>(high_resolution_clock::now() - event._clock).count();
    if (typeid(T) == typeid(std::chrono::seconds)) {
      os << " s." << std::endl;
    } else if (typeid(T).hash_code() ==
        typeid(std::chrono::milliseconds).hash_code()) {
      os << " ms." << std::endl;
    } else {
      os << " unknown." << std::endl;
    }
  }

 private:
  struct event {
    std::string _name;
    high_resolution_clock::time_point _clock;
    event(std::string name)
        : _name(name), _clock(high_resolution_clock::now()) {}
  };

  static std::stack<event> _events;
};

#endif