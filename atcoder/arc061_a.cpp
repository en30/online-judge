#include <bits/stdc++.h>
#include "../include/template"

int main() {
  string S;
  cin >> S;

  ll ans = 0;
  const int N = S.size() - 1;
  rep(s, (1 << N)) {
    int j = -1;
    rep(i, N) {
      if ((s >> i) & 1) {
        ans += stoll(S.substr(j + 1, i - j));
        j = i;
      }
    }
    ans += stoll(S.substr(j + 1, N - j));
  }

  cout << ans << endl;

  return 0;
}
