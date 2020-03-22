#include <bits/stdc++.h>
#include "../include/template"

int main() {
  int n;
  cin >> n;

  vector<vector<int>> deg(n);
  rep(i, n - 1) {
    int u, v;
    scanf("%d %d", &u, &v);
    --u, --v;
    deg[u].push_back(i);
    deg[v].push_back(i);
  }

  int u = 0;
  vector<int> ans(n - 1, -1);
  rep(i, n) if (deg[i].size() >= 3) {
    for (auto v : deg[i]) {
      ans[v] = u++;
    }
    break;
  }

  rep(i, n - 1) if (ans[i] == -1) ans[i] = u++;
  rep(i, n - 1) printf("%d\n", ans[i]);

  return 0;
}
