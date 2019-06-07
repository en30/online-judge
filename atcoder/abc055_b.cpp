#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)

const int mod = 1e9+7;

int ans(int n) {
  if(n == 1) return 1;
  return (ll(n) * ans(n-1)) % mod;
}
int main () {
  int n;
  cin >> n;
  cout << ans(n) << endl;
  return 0;
}
