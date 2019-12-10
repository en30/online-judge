#include <bits/stdc++.h>
#include "../include/template"

int N;
vector<int> s;
int main() {
  cin >> N;
  s.resize(N);
  rep(i, N) cin >> s[i];

  ll ans = 0;
  for (int c = 1; c <= N - 1; ++c) {
    ll score = 0;
    vector<bool> used(N, false);
    for (int i = 0; i < N - 1; i += c) {
      if (N - 1 - i - c <= 0) break;
      if (used[i] || used[N - 1 - i] || i == N - 1 - i) break;
      score += ll(s[i]) + s[N - 1 - i];
      used[i] = used[N - 1 - i] = true;
      ans = max(ans, score);
    }
  }

  cout << ans << endl;
  return 0;
}
