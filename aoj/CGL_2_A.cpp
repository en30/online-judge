#include <bits/stdc++.h>
#include "../include/template"
#include "../include/geometry.hpp"

int main() {
  int q;
  cin >> q;
  rep(i, q) {
    Segment s1, s2;
    cin >> s1 >> s2;
    if (isParallel(s1, s2)) {
      cout << 2;
    } else if (isOrthogonal(s1, s2)) {
      cout << 1;
    } else {
      cout << 0;
    }
    cout << endl;
  }
  return 0;
}
