#include <bits/stdc++.h>
#include "../include/template"
#include "../include/geometry.hpp"

int main() {
  int n;
  cin >> n;
  Polygon P(n);
  rep(i, n) cin >> P[i];

  int q;
  cin >> q;
  rep(i, q) {
    Point p;
    cin >> p;
    cout << contains(P, p) << endl;
  }
  return 0;
}
