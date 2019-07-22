#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)

int N, D;
int X[11][11];

int main () {
  cin >> N >> D;
  rep(i,N)rep(j,D) cin >> X[i][j];

  int ans = 0;
  rep(i,N) {
    for(int j = i+1; j < N; j++) {
      int d2 = 0;
      rep(d,D) d2 += (X[i][d] - X[j][d]) * (X[i][d] - X[j][d]);
      int d = sqrt(d2);
      ans += (d*d == d2);
    }
  }

  cout << ans << endl;
  return 0;
}
