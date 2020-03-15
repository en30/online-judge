#include <bits/stdc++.h>
#include "../include/template"

int main() {
  int Q;
  cin >> Q;

  const int D = 30;

  auto solve = [&](ll a, ll b, ll c, ll d) {
    ll ans = abs(c - a) + abs(d - b);
    ll s = 1;
    rep(i, D) s *= 3;

    ans = abs(c - a) + abs(d - b);
    while (true) {
      s /= 3;
      if (s <= 0) break;

      ll ia = a / s, ic = c / s;
      if (ia != ic) break;

      ll jb = b / s, jd = d / s;
      if (abs(jb - jd) <= 1 || ia % 3 != 1) continue;

      ll r = (ia + 1) * s, l = ia * s - 1;
      ans += 2 * min(r - max(a, c), min(a, c) - l);
      break;
    }
    return ans;
  };

  rep(i, Q) {
    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    --a, --b, --c, --d;
    cout << max(solve(a, b, c, d), solve(b, a, d, c)) << endl;
  }

  return 0;
}
