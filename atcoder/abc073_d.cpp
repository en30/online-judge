#include <bits/stdc++.h>
#include "../include/template"

#include "../include/floyd_warshall.hpp"

int N, M, R;

vector<int> r;
vector<vector<ll>> G;

int main() {
  cin >> N >> M >> R;
  r.resize(R);
  G.resize(N, vector<ll>(N, numeric_limits<ll>::max() / 2));

  rep(i, R) {
    cin >> r[i];
    r[i]--;
  }

  rep(i, M) {
    int A, B, C;
    cin >> A >> B >> C;
    A--, B--;
    G[A][B] = C;
    G[B][A] = C;
  }

  FloydWarshall<ll> fw(G);

  ll ans = numeric_limits<ll>::max();
  sort(all(r));
  do {
    ll c = 0;
    rep(i, R - 1) c += fw.dist(r[i], r[i + 1]);
    ans = min(ans, c);
  } while (next_permutation(all(r)));

  cout << ans << endl;
  return 0;
}
