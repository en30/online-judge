#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)
#define all(a) (a).begin(), (a).end()

int N, M;

struct Edge {
  int to, d;
};

vector<vector<Edge>> G;
vector<int> skip, visited;

bool findContradiction(int i, int d, map<int, int> &ds) {
  if(ds.find(i) != ds.end()) return ds[i] != d;

  visited[i] = 1;
  ds[i] = d;
  bool res = false;
  for(auto &e: G[i]) {
    res |= findContradiction(e.to, d + e.d, ds);
  }
  return res;
}

bool contradictory() {
  bool res = false;
  rep(i,N) {
    if(skip[i]) continue;
    map<int, int> ds;
    res |= findContradiction(i, 0, ds);
  }
  return res || any_of(all(visited), [](int v){ return v == 0; });
}

int main () {
  cin >> N >> M;
  G.resize(N);
  visited.resize(N, 0);
  skip.resize(N, 0);

  rep(i,M) {
    int L, R, D;
    cin >> L >> R >> D;
    L--, R--;
    G[L].push_back(Edge{R, D});
    skip[R] = true;
  }

  cout << (contradictory() ? "No" : "Yes") << endl;

  return 0;
}
