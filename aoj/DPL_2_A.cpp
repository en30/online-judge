#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i, N) for (int i = 0; i < (int)N; i++)

#define V_MAX 15
int d[V_MAX][V_MAX];
int INF = 10000;
int dp[1<<V_MAX][V_MAX];
int V, E;

int solve(int T, int u) {
  if(dp[T][u] != -1) return dp[T][u];
  int res = INF;
  for(int v = 1; v < V; v++) {
    if((T & (1 << v)) && u != v) res = min(res, solve(T & ~(1 << u), v) + d[v][u]);
  }
  dp[T][u] = res;
  return res;
}

int main () {
  REP(i, 1<<V_MAX)REP(j,V_MAX) dp[i][j] = -1;
  REP(i,V_MAX)REP(j,V_MAX) d[i][j] = INF;
  int s, t, w, res;
  cin >> V >> E;
  REP(i, E) {
    cin >> s >> t >> w;
    d[s][t] = w;
  }

  dp[1][0] = 0;
  for(int i = 1; i < V; i++) dp[1 | (1<<i)][i] = d[0][i];

  res = INF;
  for(int v = 1; v < V; v++) {
    res = min(res, solve((1<<V) - 1, v) + d[v][0]);
  }
  if(res == INF) res = -1;

  cout << res << endl;
  return 0;
}
