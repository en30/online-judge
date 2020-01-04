#include <bits/stdc++.h>
#include "../include/template"

ll N, H, A, B, C, D, E;
int main() {
  cin >> N >> H >> A >> B >> C >> D >> E;

  ll ans = 1e18;
  for (ll i = 0; i <= N; ++i) {
    ll j =
        max(0LL, (ll)floor((double)((N - i) * E - H - D * i) / (B - D)) + 1LL);

    if (j > i) continue;
    ans = min(ans, A * j + C * (i - j));
  }

  cout << ans << endl;

  return 0;
}
