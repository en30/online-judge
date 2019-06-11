#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)

int N;
vector<int> x, y, h;

int solve(int i, int j) {
  int H = -1;
  int Hmax = 1e9 + 300;
  rep(k,N) {
    int d = abs(x[k] - i) + abs(y[k] - j);
    if(h[k] == 0) {
      Hmax = min(Hmax, d);
    } else {
      int t = h[k] + d;
      if(H != -1 && t != H) return -1;
      H = t;
    }
    if(H > Hmax) return -1;
  }
  return H == -1 ? Hmax : H;
}

int main () {

  cin >> N;

  x = vector<int>(N);
  y = vector<int>(N);
  h = vector<int>(N);
  rep(i,N) {
    cin >> x[i] >> y[i] >> h[i];
  }

  rep(i,101) {
    rep(j,101) {
      int res = solve(i, j);
      if(res != -1) {
        printf("%d %d %d\n", i, j, res);
        return 0;
      }
    }
  }
  return 0;
}
