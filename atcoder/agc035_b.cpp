#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)


vector<vector<int>> G;

vector<int> parent, used, outDegree;
vector<vector<int>> nodesAt;

void dfs(int u, int d) {
  used[u] = 1;
  nodesAt[d].push_back(u);
  for(int v : G[u]) {
    if(used[v]) continue;
    parent[v] = u;
    dfs(v, d+1);
  }
}

int main () {
  int N, M;
  cin >> N >> M;

  G.resize(N);

  rep(i,M) {
    int a, b;
    cin >> a >> b;
    a--; b--;
    G[a].push_back(b);
    G[b].push_back(a);
  }

  if(M % 2) {
    cout << -1 << endl;
    return 0;
  }

  parent.resize(N, 0);
  outDegree.resize(N, 0);
  used.resize(N, 0);
  nodesAt.resize(N);

  dfs(0, 0);

  rep(u,N) {
    for(int v: G[u]) {
      if(u < v && parent[v] != u && parent[u] != v) {
        printf("%d %d\n", u+1, v+1);
        outDegree[u]++;
      }
    }
  }

  for(int d = N - 1; d > 0; d--) {
    for(int u: nodesAt[d]) {
      int v = parent[u];
      if(outDegree[u] % 2) {
        printf("%d %d\n", u+1, v+1);
        outDegree[u]++;
      } else {
        printf("%d %d\n", v+1, u+1);
        outDegree[v]++;
      }
    }
  }

  return 0;
}
