#include <bits/stdc++.h>
#include "../include/template"

struct Mon {
  ll X, H;

  bool operator<(const Mon& that) const { return X < that.X; }
};

int main() {
  int N;
  ll D, A;
  cin >> N >> D >> A;

  vector<Mon> M(N);
  rep(i, N) cin >> M[i].X >> M[i].H;

  sort(all(M));

  ll ans = 0, cum = 0;
  queue<pair<ll, ll>> q;
  rep(i, N) {
    while (!q.empty() && q.front().first < M[i].X) {
      cum -= q.front().second;
      q.pop();
    }

    ll h = M[i].H - cum;
    if (h <= 0) continue;
    ll k = (h + A - 1) / A;

    ans += k;
    q.emplace(M[i].X + 2 * D, A * k);
    cum += A * k;
  }

  cout << ans << endl;

  return 0;
}
