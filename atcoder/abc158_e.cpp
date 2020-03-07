#include <bits/stdc++.h>
#include "../include/template"

int main() {
  int N, P;
  cin >> N >> P;
  string S;
  cin >> S;

  if (P == 2 || P == 5) {
    vector<vector<ll>> dp(N + 1, vector<ll>(P, 0));
    rep(i, N) rep(p, P) {
      dp[i + 1][(p * 10 + (S[i] - '0')) % P] += dp[i][p] + (p == 0);
    }
    ll s = 0;
    rep(i, N + 1) s += dp[i][0];
    cout << s << endl;
  } else {
    vector<ll> T(N + 1, 0);
    reverse(all(S));
    ll r = 1;
    rep(i, N) {
      T[i + 1] = T[i] + r * (S[i] - '0');
      T[i + 1] %= P;
      r *= 10;
      r %= P;
    }

    ll ans = 0;
    map<ll, ll> C;
    rep(i, N + 1) {
      ans += C[T[i]];
      ++C[T[i]];
    }
    cout << ans << endl;
  }

  return 0;
}
