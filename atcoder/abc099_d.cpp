#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)

int N, C;
int c[501][5001];
int D[1001][10001];
int DS[2001][31];

int main () {
  cin >> N >> C;
  for(int i = 1; i <= C; i++) {
    for(int j = 1; j <= C; j++) {
      cin >> D[i][j];
    }
  }

  for(int i = 1; i <= N; i++) {
    for(int j = 1; j <= N; j++) {
      cin >> c[i][j];
    }
  }

  for(int k = 1; k <= C; k++) {
    for(int i = 1; i <= N; i++) {
      for(int j = 1; j <= N; j++) {
        DS[i+j-1][k] += D[c[i][j]][k];
      }
    }
  }

  ll ans = 1e15;
  for(int c1 = 1; c1 <= C; c1++) {
    for(int c2 = 1; c2 <= C; c2++) {
      if(c1 == c2) continue;
      for(int c3 = 1; c3 <= C; c3++) {
        if(c1 == c3 || c2 == c3) continue;

        ll res = 0;
        for(int l = 1; l <= 2*N-1; l++) {
          if(l % 3 == 0) {
            res += DS[l][c1];
          } else if (l % 3 == 1){
            res += DS[l][c2];
          } else {
            res += DS[l][c3];
          }
        }
        ans = min(ans, res);
      }
    }
  }

  cout << ans << endl;

  return 0;
}
