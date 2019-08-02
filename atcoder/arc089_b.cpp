#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)
#define all(a) (a).begin(), (a).end()

int N, K;

int main () {
  cin >> N >> K;

  int T = 2*K;
  vector<vector<vector<int>>> C(2, vector<vector<int>>(T, vector<int>(T, 0)));

  rep(i,N) {
    int x, y;
    char c;
    cin >> x >> y >> c;
    C[c == 'B'][y%T][x%T]++;
  }

  vector<vector<vector<int>>> SC(2, vector<vector<int>>(T+1, vector<int>(T+1, 0)));
  rep(c, 2) rep(i,T) rep(j,T) {
    SC[c][i+1][j+1] = C[c][i][j] + SC[c][i+1][j] + SC[c][i][j+1] - SC[c][i][j];
  }

  // [x0, x1) x [y0, y1)
  auto rangeSum = [&](int c, int y0, int y1, int x0, int x1) {
    return SC[c][y1][x1] - SC[c][y0][x1] - SC[c][y1][x0] + SC[c][y0][x0];
  };

  int ans = 0;
  rep(i,T) rep(j,T) {
    int flip = (j < K) ^ (i < K);
    int x1 = (j+K) % T, x2 = j;
    if(x1 > x2)swap(x1, x2);
    int y1 = (i+K) % T, y2 = i;
    if(y1 > y2)swap(y1, y2);

    ans = max(ans,
              rangeSum(flip^1, 0, y1, 0, x1) + rangeSum(flip^0, 0, y1, x1, x2) + rangeSum(flip^1, 0, y1, x2, T) +
              rangeSum(flip^0, y1, y2, 0, x1) + rangeSum(flip^1, y1, y2, x1, x2) + rangeSum(flip^0, y1, y2, x2, T) +
              rangeSum(flip^1, y2, T, 0, x1) + rangeSum(flip^0, y2, T, x1, x2) + rangeSum(flip^1, y2, T, x2, T));
  }

  cout << ans << endl;
  return 0;
}
