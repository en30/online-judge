#include <bits/stdc++.h>
#include "../include/template"
#include "../include/undirected_tree.hpp"

int main() {
  int n, x;
  cin >> n >> x;
  --x;

  vector<int> h(n);
  rep(i, n) cin >> h[i];

  UndirectedTree G(n);
  cin >> G;

  int ans = 0;
  function<bool(int, int)> found = [&](int u, int p) {
    bool res = (h[u] > 0);
    for (int v : G[u]) {
      if (v == p) continue;

      if (found(v, u)) {
        res = true;
        ans += 2;
      }
    }
    return res;
  };

  found(x, -1);
  cout << ans << endl;

  return 0;
}
