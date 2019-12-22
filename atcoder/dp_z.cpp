#include <bits/stdc++.h>
#include "../include/template"
#include "../include/li_chao_tree.hpp"

int N;
ll C;
vector<ll> h;
int main() {
  cin >> N >> C;
  h.resize(N);
  rep(i, N) cin >> h[i];

  vector<ll> dp(N, 0);
  LiChaoTree<ll> t(h);
  for (int i = 1; i < N; ++i) {
    int j = i - 1;
    t.insert(-2LL * h[j], dp[j] + h[j] * h[j]);
    dp[i] = t.y(i) + h[i] * h[i] + C;
  }

  cout << dp[N - 1] << endl;
  return 0;
}
