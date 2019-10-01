#include <bits/stdc++.h>
#include "../include/template"

int N, T;
vector<int> t;
int main() {
  cin >> N >> T;
  t.resize(N);
  rep(i, N) cin >> t[i];

  ll ans = T;
  for (int i = 1; i < N; ++i) {
    int dt = t[i] - t[i - 1];
    ans += (dt < T ? dt : T);
  }

  cout << ans << endl;
  return 0;
}
