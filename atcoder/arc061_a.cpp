#include <bits/stdc++.h>
#include "../include/template"

int main() {
  string S;
  cin >> S;

  ll ans = 0;
  const int N = S.size() - 1;
  rep(s, (1 << N)) {
    ll v = 0;
    rep(i, N + 1) {
      v *= 10;
      v += S[i] - '0';
      if (i < N && ((s >> i) & 1)) {
        ans += v;
        v = 0;
      }
    }
    ans += v;
  }

  cout << ans << endl;

  return 0;
}
