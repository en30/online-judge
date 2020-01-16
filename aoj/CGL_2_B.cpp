#include <bits/stdc++.h>
#include "../include/template"
#include "../include/geometry.hpp"

int main() {
  int q;
  cin >> q;
  rep(i, q) {
    Segment s1, s2;
    cin >> s1 >> s2;
    cout << (intersect(s1, s2) ? 1 : 0) << endl;
  }
  return 0;
}
