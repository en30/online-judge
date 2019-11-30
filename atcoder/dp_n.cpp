#include <bits/stdc++.h>
#include "../include/template"

const ll INF = 1e18;
int N;
vector<int> a;
vector<ll> S;
vector<vector<ll>> memo;

// [l, r]
ll minCost(int l, int r) {
  assert(0 <= l && l <= N - 1);
  assert(0 <= r && r <= N - 1);
  assert(l <= r);

  if (l == r) return 0;
  if (memo[l][r] != -1) return memo[l][r];

  ll res = INF;
  for (int i = l; i < r; ++i) {
    res = min(res, minCost(l, i) + minCost(i + 1, r));
  }
  return memo[l][r] = res + S[r + 1] - S[l];
}

int main() {
  cin >> N;
  a.resize(N);
  S.resize(N + 1, 0);
  memo.resize(N, vector<ll>(N, -1));

  rep(i, N) cin >> a[i];
  rep(i, N) S[i + 1] = S[i] + a[i];

  cout << minCost(0, N - 1) << endl;

  return 0;
}
