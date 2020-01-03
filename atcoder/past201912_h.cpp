#include <bits/stdc++.h>
#include "../include/template"

int N, Q;
vector<ll> C;

int main() {
  cin >> N;
  C.resize(N);
  rep(i, N) cin >> C[i];

  ll eMin = 1e9 + 1, oMin = 1e9 + 1;
  rep(i, N) {
    if (i % 2 == 0) {
      eMin = min(eMin, C[i]);
    } else {
      oMin = min(oMin, C[i]);
    }
  }

  ll ans = 0, ea = 0, oa = 0;
  cin >> Q;
  rep(i, Q) {
    int t, x, a;
    cin >> t;
    if (t == 1) {
      cin >> x >> a;
      --x;
      if (x % 2 == 0) {
        if (C[x] - ea - a < 0) continue;
        C[x] -= a;
        ans += a;

        eMin = min(eMin, C[x] - ea);
      } else {
        if (C[x] - oa - a < 0) continue;
        C[x] -= a;
        ans += a;

        oMin = min(oMin, C[x] - oa);
      }
    } else if (t == 2) {
      cin >> a;
      if (eMin - a < 0) continue;

      eMin -= a;
      ans += a * ((N + 1) / 2);
      ea += a;
    } else {
      cin >> a;
      if (oMin - a < 0 || eMin - a < 0) continue;

      eMin -= a;
      oMin -= a;
      ans += a * N;
      ea += a;
      oa += a;
    }
  }

  cout << ans << endl;
  return 0;
}
