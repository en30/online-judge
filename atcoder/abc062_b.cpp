#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i, N) for (int i = 0; i < (int)N; i++)

char a[100][100];

int main () {
  int H, W;
  cin >> H >> W;

  REP(i,H)REP(j,W) {
    cin >> a[i][j];
  }

  REP(i,H+2) {
    REP(j,W+2) {
      if(i == 0 || i == H+1 || j == 0 || j == W+1) {
        cout << '#';
      } else {
        cout << a[i-1][j-1];
      }
    }
    cout << endl;
  }

  return 0;
}
