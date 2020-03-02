#include <bits/stdc++.h>
#include "../include/template"

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i, n) cin >> a[i];

  sort(all(a));

  // [l, r)
  using It = vector<int>::iterator;
  function<int(It, It, int, int)> f = [&](It l, It r, int d, int res) {
    if (d == -1) return res;
    It it =
        partition_point(l, r, [&](const int& e) { return !((e >> d) & 1); });
    if (it == l || it == r) return f(l, r, d - 1, res);
    return min(f(l, it, d - 1, res | (1 << d)),
               f(it, r, d - 1, res | (1 << d)));
  };

  cout << f(a.begin(), a.end(), 30, 0) << endl;

  return 0;
}
