#include <bits/stdc++.h>
#include "../include/template"

int main() {
  int N, M;
  cin >> N >> M;
  vector<int> P(N + 1, 0);
  rep(i, N) cin >> P[i + 1];

  vector<int> P2;
  rep(i, N + 1) rep(j, N + 1) P2.push_back(P[i] + P[j]);

  sort(all(P2));

  int ans = 0;
  rep(i, P2.size()) {
    auto it = upper_bound(all(P2), M - P2[i]);
    if (it == P2.begin()) continue;
    chmax(ans, P2[i] + *prev(it));
  }

  cout << ans << endl;

  return 0;
}
