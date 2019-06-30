#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)

struct cand {
  int u, n;
};

vector<vector<int>> dist;
vector<vector<int>> adj;
queue<cand> q;

void kkp(int n, int i, int u) {
  if(dist[u][i] != -1) return;

  dist[u][i] = n;
  if(i == 0) {
    q.push(cand{u, n});
    return;
  }

  for(auto v: adj[u]) kkp(n, i-1, v);
}

int main () {
  int N, M;
  cin >> N >> M;
  adj = vector<vector<int>>(N+1);

  rep(i,M) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
  }

  int S, T;
  cin >> S >> T;

  dist = vector<vector<int>>(N+1, vector<int>(4, -1));
  q.push(cand{S, 0});

  while(!q.empty()) {
    cand c = q.front(); q.pop();
    kkp(c.n + 1, 3, c.u);
  }

  cout << dist[T][0] << endl;

  return 0;
}
