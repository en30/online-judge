#include <bits/stdc++.h>
#include "../include/template"
#include "../include/geometry.hpp"

int main() {
  Point p1, p2, p3;
  cin >> p1 >> p2;
  int q;
  cin >> q;
  rep(i, q) {
    cin >> p3;
    switch (ccw(p1, p2, p3)) {
      case COUNTER_CLOCKWISE:
        cout << "COUNTER_CLOCKWISE";
        break;
      case CLOCKWISE:
        cout << "CLOCKWISE";
        break;
      case ONLINE_BACK:
        cout << "ONLINE_BACK";
        break;
      case ONLINE_FRONT:
        cout << "ONLINE_FRONT";
        break;
      case ON_SEGMENT:
        cout << "ON_SEGMENT";
        break;
    }
    cout << endl;
  }
  return 0;
}
