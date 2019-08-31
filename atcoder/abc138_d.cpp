#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)
#define all(a) (a).begin(), (a).end()

int N, Q;
vector<vector<int>> G;
vector<ll> c, res;

void dfs(int u, int p, ll w) {
  c[u] += w;
  for(int v: G[u]) {
    if(v != p) dfs(v, u, c[u]);
  }
}

int main () {
  cin >> N >> Q;

  G.resize(N+1);
  rep(i,N-1) {
    int a, b;
    cin >> a >> b;
    G[a].push_back(b);
    G[b].push_back(a);
  }

  c.resize(N+1, 0);
  res.resize(N+1, 0);
  rep(i,Q) {
    int p, x;
    cin >> p >> x;
    c[p] += x;
  }

  dfs(1, -1, 0);

  rep(i,N) {
    if(i != 0) cout << " ";
    cout << c[i+1];
  }
  cout << endl;

  return 0;
}
