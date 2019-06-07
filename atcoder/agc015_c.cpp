#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i, N) for (int i = 0; i < (int)N; i++)

int svx[2002][2002];
int svy[2002][2002];
int sv[2002][2002];
char grid[2002][2002];


int main () {
  int n, m, q;

  cin >> n >> m >> q;

  for(int i = 0; i < n + 2; i++) {
    for(int j = 0; j < m + 2; j++) {
      grid[i][j] = '0';
      sv[i][j] = 0;
      svx[i][j] = 0;
      svy[i][j] = 0;
    }
  }

  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= m; j++) {
      sv[i][j] = sv[i][j-1] + sv[i-1][j] - sv[i-1][j-1];
      svx[i][j] = svx[i][j-1] + svx[i-1][j] - svx[i-1][j-1];
      svy[i][j] = svy[i][j-1] + svy[i-1][j] - svy[i-1][j-1];

      cin >> grid[i][j];
      if(grid[i][j] == '0') continue;

      sv[i][j] += 1;
      if(grid[i-1][j] == '1') svx[i][j] += 1;
      if(grid[i][j-1] == '1') svy[i][j] += 1;
    }
  }

  int x0, y0, x1, y1;
  for(int i = 0; i < q; i++) {
    cin >> x0 >> y0 >> x1 >> y1;
    int v = sv[x1][y1] - sv[x0-1][y1] - sv[x1][y0-1] + sv[x0-1][y0-1];
    int e = svy[x1][y1] - svy[x0-1][y1] - svy[x1][y0] + svy[x0-1][y0];
    e += svx[x1][y1] - svx[x0][y1] - svx[x1][y0-1] + svx[x0][y0-1];

    cout << (v - e) << endl;
  }

  return 0;
}
