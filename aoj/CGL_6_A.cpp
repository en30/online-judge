#include <bits/stdc++.h>
#include "../include/template"
#include "../include/geometry.hpp"

enum EventKind {
  IN = 0,
  QUERY = 1,
  OUT = 2,
};

struct Event {
  EventKind kind;
  double x;
  Segment s;
};

int main() {
  int n;
  cin >> n;
  vector<Event> events;
  rep(i, n) {
    Point p1, p2;
    cin >> p1 >> p2;
    if (p1.x > p2.x) swap(p1, p2);
    if (p1.y > p2.y) swap(p1, p2);
    if (p1.x == p2.x) {
      events.push_back(Event{QUERY, p1.x, Segment(p1, p2)});
    } else {
      events.push_back(Event{IN, p1.x, Segment(p1, p2)});
      events.push_back(Event{OUT, p2.x, Segment(p1, p2)});
    }
  }

  sort(all(events), [](const Event& a, const Event& b) {
    return a.x == b.x ? a.kind < b.kind : a.x < b.x;
  });

  set<int> ys;

  ll ans = 0;
  for (Event& e : events) {
    if (e.kind == QUERY) {
      ans += distance(ys.lower_bound(e.s.p1.y), ys.lower_bound(e.s.p2.y + 1));
    } else if (e.kind == IN) {
      ys.insert(e.s.p1.y);
    } else if (e.kind == OUT) {
      ys.erase(e.s.p1.y);
    }
  }

  cout << ans << endl;

  return 0;
}
