#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)

int main () {
  int n;
  cin >> n;
  vector<ll> s(n+1, 0);
  rep(i,n) {
    int a;
    cin >> a;
    s[i+1] = s[i] + a;
  }

  ll ans = 2e15;

  rep(i,n-1) {
    ans = min(ans, abs(2*s[i+1] - s[n]));
  }
  cout << ans << endl;
  return 0;
}
