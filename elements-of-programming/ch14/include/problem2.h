#ifndef PROBLEM_2_
#define PROBLEM_2_

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

template<typename ValueType>
void quick_sort(vector<ValueType>& v, int l, int h) {
  if (l > h) {
    return;
  }

  // partition
  int p = partition(v, l, h);

  if ((p-1) > l) {
    quick_sort(v, l, p-1);
  }

  if ((p+1) < h) {
    quick_sort(v, p+1, h);
  }
}

template<typename ValueType>
int partition(vector<ValueType>& v, int l, int h) {
  ValueType pivot = v[h];

  int r = l, i = l;
  while(i < h) {
    if(v[i] < pivot) {
      ValueType tmp = v[r];
      v[r] = v[i];
      v[i] = tmp;
      ++r;
    }

    ++i;
  }

  v[h] = v[r];
  v[r] = pivot;

  return r;
}

struct Event {
  Event(std::string name, int b, int e) : name(name), b(b), e(e) {};

  std::string name;
  int b;
  int e;
};

struct Endpoint {
  bool operator<(const Endpoint& rhs) const {
    return time != rhs.time ? 
      time < rhs.time : 
      (isStart && !rhs.isStart); // contiguous intervals are considered overlapping
  }

  int time;
  bool isStart;
};

int max_concurrent_events(const vector<Event>& events) {
  vector<Endpoint> endpoints;
  for (const Event& e : events) {
    endpoints.emplace_back(Endpoint{e.b, true});
    endpoints.emplace_back(Endpoint{e.e, false});
  }

  // O(nlogn)
  // sort(endpoints.begin(), endpoints.end());
  quick_sort(endpoints, 0, endpoints.size()-1);

  int max_events = 0, count = 0;
  for (const Endpoint& e : endpoints) {
    if (e.isStart) {
      max_events = max(++count, max_events);
    } else {
      count--;
    }
  }

  return max_events;
}

#endif