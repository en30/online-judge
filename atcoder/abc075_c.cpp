#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)
#define all(a) (a).begin(), (a).end()

int N, M;
vector<vector<int>> G;

void dfs(vector<bool> &used, int u, int v, int c) {
  used[c] = true;
  for(auto n: G[c]) {
    if(used[n] || (u == c && v == n) || (v == c && u == n)) continue;
    dfs(used, u, v, n);
  }
}

bool isBridge(int u, int v) {
  vector<bool> used(N, false);
  dfs(used, u, v, u);
  return !used[v];
}

int main () {
  cin >> N >> M;

  G.resize(N);
  rep(i,M) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    G[u].push_back(v);
    G[v].push_back(u);
  }

  int ans = 0;
  rep(i,N) {
    for(int j: G[i]) {
      ans += isBridge(i, j);
    }
  }

  cout << ans/2 << endl;

  return 0;
}
