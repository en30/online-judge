#include <bits/stdc++.h>
#include "../include/template"

int N;
vector<int> d;

int main() {
  cin >> N;
  d.resize(N);
  rep(i, N) cin >> d[i];

  int ans = 0;
  rep(i, N) for (int j = i + 1; j < N; ++j) { ans += d[i] * d[j]; }

  cout << ans << endl;
  return 0;
}
