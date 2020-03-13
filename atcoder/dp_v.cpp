#include <bits/stdc++.h>
#include "../include/template"
#include "../include/undirected_tree.hpp"
#include "../include/re_rooting.hpp"

int N, M;

ll reduce(ll prod, ll v) { return ((v + 1) * prod) % M; }

int main() {
  cin >> N >> M;

  UndirectedTree T(N);
  cin >> T;

  ReRooting<ll, ll> subtreeCount(
      T.adjacencyList(), reduce, [](int u, ll a, ll b) { return (a * b) % M; },
      [](int i) { return 1LL; }, -1);

  rep(i, N) cout << subtreeCount.value(i, -1) << endl;

  return 0;
}
