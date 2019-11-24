#include <bits/stdc++.h>
#include "../include/template"

int N, K;
vector<int> h;

int main() {
  cin >> N >> K;
  h.resize(N);
  rep(i, N) cin >> h[i];

  int ans = 0;
  rep(i, N) if (h[i] >= K) ans++;
  cout << ans << endl;
  return 0;
}
