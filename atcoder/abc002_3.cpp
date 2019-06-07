#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)

int main () {
  int xa, ya, xb, yb, xc, yc;

  cin >> xa >> ya >> xb >> yb >> xc >> yc;

  double ans = abs((xc-xa)*(yb-ya) - (yc-ya)*(xb-xa)) / 2.0;
  printf("%.3lf\n", ans);

  return 0;
}
