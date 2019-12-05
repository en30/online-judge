#include <bits/stdc++.h>
#include "../include/template"

int N;
vector<vector<int>> a;

int S;
vector<ll> score, memo;

ll f(int s) {
  if (memo[s] != -1) return memo[s];

  ll res = -1e20;
  for (int t = (-s) & s; t != 0; t = (t - s) & s) {
    res = max(res, score[t] + f(s & ~t));
  }
  return memo[s] = res;
}

int main() {
  cin >> N;
  a.resize(N, vector<int>(N));
  rep(i, N) rep(j, N) cin >> a[i][j];

  S = 1 << N;
  memo.resize(S, -1);
  memo[0] = 0;
  score.resize(S, 0);

  rep(s, S) {
    rep(i, N) for (int j = i + 1; j < N; ++j) {
      if (((s >> i) & 1) && ((s >> j) & 1)) score[s] += a[i][j];
    }
  }

  cout << f(S - 1) << endl;

  return 0;
}
