#include <bits/stdc++.h>
#include "../include/template"

pair<int, int> divide(int l, int n) {
  for (int i = l; i * i < n; ++i) {
    if (n % i == 0) {
      return make_pair(i, n / i);
    }
  }
  return make_pair(-1, -1);
}

void no() { cout << "NO" << endl; }

void solve() {
  int n;
  cin >> n;
  auto p = divide(2, n);
  if (p.first == -1) return no();
  auto p2 = divide(p.first + 1, p.second);
  if (p2.first == -1) return no();
  cout << "YES" << endl;
  cout << p.first << " " << p2.first << " " << p2.second << endl;
}

int main() {
  int t;
  cin >> t;
  rep(i, t) solve();
  return 0;
}
