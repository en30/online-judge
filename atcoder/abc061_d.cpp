#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i, N) for (int i = 0; i < (int)N; i++)

const ll INF = 1e18;
struct edge { int from, to; ll cost; };

const int M_MAX = 2000;

int main () {
  int N, M, a, b;
  ll c;

  cin >> N >> M;
  vector<edge> edges(M);
  REP(i,M) {
    edge e;
    cin >> a >> b >> c;
    e.from = a - 1;
    e.to = b - 1;
    e.cost = -c;
    edges[i] = e;
  }

  vector<ll> distances(N, INF);
  distances[0] = 0;

  REP(i,N) REP(j,M) {
    edge e = edges[j];
    if(distances[e.from] != INF && distances[e.to] > distances[e.from] + e.cost) {
      distances[e.to] = distances[e.from] + e.cost;
    }
  }

  vector<bool> negative(N, false);
  REP(i,N) REP(j,M) {
    edge e = edges[j];
    if(distances[e.from] != INF && distances[e.to] > distances[e.from] + e.cost) {
      distances[e.to] = distances[e.from] + e.cost;
      negative[e.to] = true;
    }
    if(negative[e.from]) negative[e.to] = true;
  }

  if(negative[N-1]) {
    cout << "inf" << endl;
  } else {
    cout << -distances[N-1] << endl;
  }
  return 0;
}
