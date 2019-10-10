#include <bits/stdc++.h>
#include "../include/template"

const int MOD = 1000000007;
int N;

int main() {
  cin >> N;
  vector<int> x(N), r(N + 1, 0);
  rep(i, N) x[i] = i + 1;
  rep(i, N) {
    if (x[i] == 1) continue;
    rep(j, N) {
      if (i == j) continue;
      if (x[j] % x[i] == 0) {
        x[j] /= x[i];
        r[x[i]] += 1;
      }
    }
    r[x[i]] += 1;
    x[i] = 1;
  }

  ll ans = 1;
  rep(i, N) ans = (ans * (r[i + 1] + 1)) % MOD;

  cout << ans << endl;
  return 0;
}
