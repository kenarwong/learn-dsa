#include "problem2.h"
#include <iostream>
#include <cassert>

void TestMaxConcurrentEvents1() {
  std::vector<Event> events = {
    Event("E1", 1, 5),
    Event("E2", 6, 10),
    Event("E3", 11, 13),
    Event("E4", 14, 15),
    Event("E5", 2, 7),
    Event("E6", 8, 9),
    Event("E7", 12, 15),
    Event("E8", 4, 5),
    Event("E9", 9, 17)
  };

  int max_events = max_concurrent_events(events);
  assert(max_events == 3);

  events.clear();

  events.emplace_back("E1", 1, 5);
  events.emplace_back("E2", 6, 10);
  events.emplace_back("E3", 11, 13);
  events.emplace_back("E4", 14, 15);
  events.emplace_back("E5", 4, 7);
  events.emplace_back("E6", 8, 9);
  events.emplace_back("E7", 12, 15);
  events.emplace_back("E8", 2, 3);
  events.emplace_back("E9", 0, 1);

  max_events = max_concurrent_events(events);
  assert(max_events == 2);

  events.clear();

  events.emplace_back("E1", 1, 5);
  events.emplace_back("E2", 1, 4);
  events.emplace_back("E3", 1, 3);
  events.emplace_back("E4", 1, 2);

  max_events = max_concurrent_events(events);
  assert(max_events == 4);
}

int main()
{
  std::cout << "Problem 2" << std::endl;
  TestMaxConcurrentEvents1();

  return 0;
}