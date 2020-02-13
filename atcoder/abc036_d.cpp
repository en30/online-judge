#include <bits/stdc++.h>
#include "../include/template"
#include "../include/mod.hpp"

vector<vector<int>> G;

unordered_map<int, unordered_map<int, unordered_map<bool, ModInt>>> memo;

ModInt color(int u, int p, bool black) {
  if (memo[u][p][black] != 0) return memo[u][p][black];

  ModInt res(1);
  for (int v : G[u]) {
    if (v == p) continue;
    if (black) {
      res *= color(v, u, false);
    } else {
      res *= (color(v, u, false) + color(v, u, true));
    }
  }
  return memo[u][p][black] = res;
}

int main() {
  int N;
  cin >> N;
  G.resize(N);

  rep(i, N - 1) {
    int a, b;
    cin >> a >> b;
    --a, --b;
    G[a].push_back(b);
    G[b].push_back(a);
  }

  cout << color(0, -1, false) + color(0, -1, true) << endl;
  return 0;
}
