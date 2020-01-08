#include <bits/stdc++.h>
#include "../include/template"
#include "../include/mod.hpp"

int N, M;
vector<int> f;

int main() {
  cin >> N >> M;

  f.resize(N);

  rep(i, N) cin >> f[i];

  vector<ModInt> dp(N + 1, 0);

  dp[N] = ModInt(1);
  dp[N - 1] = -ModInt(1);
  unordered_map<int, int> m;

  int l = N - 1, r = N;
  while (r > 0) {
    while (l >= 0 && !m[f[l]]) {
      m[f[l]] += 1;
      --l;
    }
    do {
      if (l >= 0) dp[l] -= dp[r];
      dp[r - 1] += dp[r] * 2;
      --r;
      m[f[r]] -= 1;
    } while (r > l && m[f[l]]);
  }

  cout << dp[0] << endl;

  return 0;
}
