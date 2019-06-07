#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)

const int mod = 1e9 + 7;

int main () {
  int n, m;
  cin >> n >> m;
  vector<int> x(n), y(m), sx(n+1, 0), sy(m+1, 0);

  rep(i,n) {
    cin >> x[i];
    sx[i+1] = (sx[i] + x[i]) % mod;
  }
  rep(i,m) {
    cin >> y[i];
    sy[i+1] = (sy[i] + y[i]) % mod;
  }

  ll xf = 0, yf = 0;
  rep(i,n) {
    xf += sx[n] - sx[i] - ll(n-i) * x[i] + mod;
    xf %= mod;
  }
  rep(i,m) {
    yf += sy[m] - sy[i] - ll(m-i) * y[i] + mod;
    yf %= mod;
  }
  printf("%d\n", (xf * yf) % mod);

  return 0;
}
