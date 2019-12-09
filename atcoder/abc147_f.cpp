#include <bits/stdc++.h>
#include "../include/template"

ll N, X, D;

// [l, r]
struct Range {
  ll l, r;

  bool operator<(const Range &that) { return l < that.l; }
};

int main() {
  cin >> N >> X >> D;

  if (D == 0) {
    cout << (X == 0 ? 1 : N + 1) << endl;
    return 0;
  }

  ll AD = abs(D);
  unordered_map<int, vector<Range>> klass;
  klass[0].push_back(Range{0, 0});

  for (int i = 1; i <= N; ++i) {
    ll l = i * X + D * i * (i - 1) / 2;
    ll r = l + D * i * (N - i);
    klass[((i * X) % AD + AD) % AD].push_back(Range{min(l, r), max(l, r)});
  }

  ll ans = 0;
  for (auto it = klass.begin(); it != klass.end(); it++) {
    int i = (*it).first;
    sort(all(klass[i]));

    int C = klass[i].size();
    rep(j, C) {
      ll l = klass[i][j].l;
      ll r = klass[i][j].r;
      while (j + 1 < C && klass[i][j + 1].l <= r) {
        ++j;
        r = max(r, klass[i][j].r);
      }
      ans += (r - l) / AD + 1;
    }
  }

  cout << ans << endl;

  return 0;
}
