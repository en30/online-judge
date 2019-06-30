#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)

int main () {
  int N, M, Q;
  cin >> N >> M >> Q;
  vector<vector<int>> x(N, vector<int>(N, 0));

  rep(i,M) {
    int L, R;
    cin >> L >> R;
    L--; R--;
    x[L][R]++;
  }
  vector<vector<int>> c(N+1, vector<int>(N+1, 0));
  rep(i,N) {
    rep(j,N) c[i+1][j+1] = c[i][j+1] + c[i+1][j] - c[i][j] + x[i][j];
  }

  rep(k,Q) {
    int p, q;
    cin >> p >> q;
    cout << c[q][q] - c[q][p-1] - c[p-1][q] + c[p-1][p-1] << endl;
  }
  return 0;
}
