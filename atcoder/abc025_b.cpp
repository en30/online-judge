#include <bits/stdc++.h>
#include "../include/template"

int main() {
  int N, A, B;
  cin >> N >> A >> B;

  int x = 0;
  rep(i, N) {
    string s;
    int d;
    cin >> s >> d;
    d = max(d, A);
    d = min(d, B);
    if (s == "East") {
      x += d;
    } else {
      x -= d;
    }
  }

  if (x == 0) {
    cout << 0 << endl;
  } else if (x > 0) {
    cout << "East " << x << endl;
  } else {
    cout << "West " << -x << endl;
  }

  return 0;
}
