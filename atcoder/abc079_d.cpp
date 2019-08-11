#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)
#define all(a) (a).begin(), (a).end()

const ll INF = 1e15;

void worshallFloyd(vector<vector <ll>> &d) {
  int V = d.size();
  for(int k = 0; k < V; k++) {
    for(int i = 0; i < V; i++) {
      for(int j = 0; j < V; j++) {
        if(d[i][k] != INF && d[k][j] != INF)d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
      }
    }
  }
}

int H, W;

int main () {
  cin >> H >> W;

  vector<vector<ll>> G(10, vector<ll>(10));
  rep(i,10)rep(j,10) cin >> G[i][j];

  worshallFloyd(G);

  ll ans = 0;
  rep(i,H)rep(j,W) {
    int A;
    cin >> A;
    if(A == -1) continue;
    ans += G[A][1];
  }

  cout << ans << endl;

  return 0;
}
