#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)

int main () {
  int H, W;
  cin >> H >> W;

  vector<vector<char>> a(H, vector<char>(W));
  rep(i,H) rep(j,W) cin >> a[i][j];

  vector<int> r(H, 0), c(W, 0);

  rep(i,H) rep(j,W) {
    if(a[i][j] == '#') {
      r[i] = 1;
      c[j] = 1;
    }
  }

  rep(i,H) {
    if(!r[i]) continue;
    rep(j,W) {
      if(!c[j]) continue;
      cout << a[i][j];
    }
    cout << endl;
  }


  return 0;
}
