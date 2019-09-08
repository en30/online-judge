#include <bits/stdc++.h>
#include "../include/template"

#include "../include/floyd_warshall.hpp"

int N;
vector<vector<int>> A;

bool hasBypaass(int u, int v) {
  rep(w,N) {
    if(u == w || v == w) continue;
    if(A[u][v] == A[u][w] + A[w][v]) return true;
  }
  return false;
}

int main () {
  cin >> N;
  A.resize(N, vector<int>(N));
  rep(i,N)rep(j,N) cin >> A[i][j];

  FloydWarshall<int> fw(A);

  ll ans = 0;

  for(int u = 0; u < N; ++u) {
    for(int v = u + 1; v < N; ++v) {
      if(fw.dist(u, v) < A[u][v]) {
        cout << "-1" << endl;
        return 0;
      }

      if(!hasBypaass(u, v)) ans += A[u][v];
    }
  }

  cout << ans << endl;

  return 0;
}
