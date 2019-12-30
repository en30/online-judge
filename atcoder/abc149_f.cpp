#include <bits/stdc++.h>
#include "../include/template"
#include "../include/mod.hpp"

int N;
vector<vector<int>> G;
unordered_map<int, unordered_map<int, int>> memo;

int count(int p, int u) {
  if (memo[p][u] != 0) return memo[p][u];
  if (memo[u][p] != 0) return N - memo[u][p];

  int res = 1;
  for (int v : G[u]) {
    if (v == p) continue;
    res += count(u, v);
  }
  return memo[p][u] = res;
}

int main() {
  cin >> N;
  G.resize(N);
  rep(i, N - 1) {
    int A, B;
    cin >> A >> B;
    --A, --B;
    G[A].push_back(B);
    G[B].push_back(A);
  }

  ModInt ans = 0;
  rep(u, N) for (int v : G[u]) {
    if (u > v) continue;
    int k = count(u, v);
    ans += (ModInt(2).pow(k) - 1) * (ModInt(2).pow(N - k) - 1);
  }
  ans -= 1;
  ans *= ModInt(2).pow(N).inverse();
  ans = ans + 1 - ModInt(N) / 2;

  cout << ans << endl;

  return 0;
}
