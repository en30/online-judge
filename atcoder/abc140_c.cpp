#include <bits/stdc++.h>
#include "../include/template"

int N;
vector<int> B;

int main() {
  cin >> N;
  B.resize(N + 1, 1e6);
  for (int i = 1; i <= N - 1; ++i) {
    cin >> B[i];
  }
  ll ans = 0;
  rep(i, N) { ans += min(B[i], B[i + 1]); }

  cout << ans << endl;
  return 0;
}
