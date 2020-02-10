#include <bits/stdc++.h>
#include "../include/template"

int main() {
  int N, K;
  cin >> N >> K;
  vector<int> s(N);
  rep(i, N) cin >> s[i];

  if (count(all(s), 0) != 0) {
    cout << N << endl;
    return 0;
  }

  int l = 0, ans = 0;
  ll p = 1;
  rep(r, N) {
    p *= s[r];
    while (l <= r && p > K) p /= s[l++];
    if (p <= K) chmax(ans, r - l + 1);
  }

  cout << ans << endl;

  return 0;
}
