#include <bits/stdc++.h>
#include "../include/template"
#include "../include/re_rooting.hpp"

int main() {
  int n;
  cin >> n;

  vector<int> a(n);
  rep(i, n) scanf("%d", &a[i]);

  vector<vector<int>> G(n);
  rep(i, n - 1) {
    int u, v;
    scanf("%d %d", &u, &v);
    --u, --v;
    G[u].push_back(v);
    G[v].push_back(u);
  }

  ReRooting<int, int> mws(
      G, [](int a, int b) { return max(a, 0) + max(b, 0); },
      [&](int i, int p1, int p2) { return p1 + p2 + (2 * a[i] - 1); },
      [](int u) { return 0; }, 1e9);

  for (int i = 0; i < (int)(n); ++i) {
    if (i) cout << " ";
    cout << mws.value(i, -1);
  }
  cout << endl;

  return 0;
}
