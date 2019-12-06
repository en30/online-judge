#include <bits/stdc++.h>
#include "../include/template"

int a, b, c, d;

int main() {
  cin >> a >> b >> c >> d;

  if (a - b == 1) {
    if (c == 0 && d == 0) {
      cout << "YES" << endl;
      cout << "0";
      rep(i, b) cout << " 1 0";
    } else {
      cout << "NO";
    }
    cout << endl;
    return 0;
  }

  if (d - c == 1) {
    if (a == 0 && b == 0) {
      cout << "YES" << endl;
      cout << "3";
      rep(i, c) cout << " 2 3";
    } else {
      cout << "NO";
    }
    cout << endl;
    return 0;
  }

  if (b < a || c < d || abs(a - b + c - d) > 1) {
    cout << "NO" << endl;
    return 0;
  }

  cout << "YES" << endl;

  bool out = false;

  auto p = [&](string s) {
    if (out) cout << " ";
    cout << s;
    out = true;
  };

  if (b - a > c - d) p("1");
  rep(i, a) p("0 1");
  rep(i, min(b - a, c - d)) p("2 1");
  rep(i, d) p("2 3");
  if (b - a < c - d) p("2");
  cout << endl;

  return 0;
}
