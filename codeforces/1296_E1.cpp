#include <bits/stdc++.h>
#include "../include/template"

int main() {
  int n;
  cin >> n;
  string s;
  cin >> s;

  const int R = int('z' - 'a') + 1;
  vector<int> count(R + 2, 0);
  for (char c : s) ++count[c - 'a' + 1];
  for (int i = 0; i < R; ++i) count[i + 1] += count[i];

  vector<int> ideal(n);
  rep(i, n) ideal[i] = count[int(s[i] - 'a')]++;

  vector<vector<int>> G(2 * n);
  auto addEdge = [&](int u, int v) {
    G[u].push_back(v);
    G[v].push_back(u);
  };
  rep(i, n) {
    rep(j, n) {
      if (i == j) continue;

      if ((j - i) * (ideal[j] - ideal[i]) < 0) {
        addEdge(2 * i, 2 * j + 1);
        addEdge(2 * i + 1, 2 * j);
      }
    }
  }

  vector<int> color(n, -1);
  function<bool(int)> dfs = [&](int u) {
    color[u / 2] = u % 2;

    for (int v : G[u]) {
      if (color[v / 2] == v % 2) continue;
      if (color[v / 2] != -1) return false;
      if (!dfs(v)) return false;
    }
    return true;
  };

  rep(i, n) {
    if (color[i] == -1 && !dfs(2 * i)) {
      cout << "NO" << endl;
      return 0;
    };
  }

  cout << "YES" << endl;
  rep(i, n) cout << color[i];
  cout << endl;

  return 0;
}
