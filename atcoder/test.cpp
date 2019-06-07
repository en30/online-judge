#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i, N) for (int i = 0; i < (int)N; i++)

const ll INF = 1e18;
struct edge { int from, to; ll cost; };

vector<vector <ll>> worshallFloyd(vector<vector <ll>> d) {
  int V = d.size();
  for(int k = 0; k < V; k++) {
    for(int i = 0; i < V; i++) {
      for(int j = 0; j < V; j++) {
        if(d[i][k] != INF && d[k][j] != INF)d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
      }
    }
  }
  return d;
}

const int M_MAX = 2000;

int main () {
  int N, M, a, b;
  ll c;

  cin >> N >> M;
  vector<vector <ll>> d(N, vector<ll>(N, INF));
  REP(i,N) d[i][i] = 0;
  REP(i,M) {
    cin >> a >> b >> c;
    d[a-1][b-1] = -c;
  }

  d = worshallFloyd(d);
  REP(i,N) {
    if(d[i][i] < 0 && (i == 0 || (d[0][i] != INF && d[i][N-1] != INF))) {
      cout << "inf" << endl;
      return 0;
    }
  }
  cout << -d[0][N-1] << endl;
  return 0;
}
