#include <bits/stdc++.h>
#include "../include/template"

int N;

struct Block {
  int w, s, v;
};

vector<Block> B;

int main() {
  cin >> N;
  B.resize(N);
  int S = 0;
  rep(i, N) {
    cin >> B[i].w >> B[i].s >> B[i].v;
    S = max(S, B[i].s + B[i].w);
  }

  sort(B.rbegin(), B.rend(),
       [&](const Block& a, const Block& b) { return a.s + a.w < b.s + b.w; });

  vector<ll> dp(S + 1, 0);

  rep(i, N) rep(j, S + 1) {
    if (j + B[i].w <= S && B[i].s >= j)
      dp[j] = max(dp[j], dp[j + B[i].w] + B[i].v);
  }

  cout << dp[0] << endl;

  return 0;
}
