#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)
#define all(a) (a).begin(), (a).end()

int N, K;

int main () {
  cin >> N >> K;

  int T = 2*K;
  vector<vector<int>> C(T, vector<int>(T, 0));

  rep(i,N) {
    int x, y;
    char c;
    cin >> x >> y >> c;
    if(c == 'W') x += K;
    C[y%T][x%T]++;
  }

  vector<vector<int>> SC(T+1, vector<int>(T+1, 0));
  rep(i,T) rep(j,T) {
    SC[i+1][j+1] = C[i][j] + SC[i+1][j] + SC[i][j+1] - SC[i][j];
  }

  // [x0, x1) x [y0, y1)
  auto rangeSum = [&](int y0, int y1, int x0, int x1) {
    return SC[y1][x1] - SC[y0][x1] - SC[y1][x0] + SC[y0][x0];
  };

  int ans = 0;
  rep(i,T) rep(j,T) {
    int x1 = (j+K) % T, x2 = j;
    if(x1 > x2)swap(x1, x2);
    int y1 = (i+K) % T, y2 = i;
    if(y1 > y2)swap(y1, y2);

    int b = rangeSum(0, y1, 0, x1)
      + rangeSum(0, y1, x2, T)
      + rangeSum(y1, y2, x1, x2)
      + rangeSum(y2, T, 0, x1)
      + rangeSum(y2, T, x2, T);

    ans = max(ans, max(b, N - b));
  }

  cout << ans << endl;
  return 0;
}
