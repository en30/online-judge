#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)

int main () {
  int n;
  cin >> n;
  vector<int> a(n);

  bool even = true;
  ll ans = 0;
  int m = 1e9 + 1;
  rep(i,n)  cin >> a[i];

  vector<ll> dp[2];
  dp[0] = vector<ll>(n+1);
  dp[1] = vector<ll>(n+1);
  dp[0][0] = 0;
  dp[1][0] = - 1e15;

  rep(i,n) {
    dp[0][i+1] = max(dp[0][i] + a[i], dp[1][i] - a[i]);
    dp[1][i+1] = max(dp[0][i] - a[i], dp[1][i] + a[i]);
  }

  cout << dp[0][n] << endl;

  return 0;
}
