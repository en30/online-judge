#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)

int main () {
  int n, m;
  cin >> n >> m;
  vector<pair<ll,ll>> ab(n);
  rep(i,n) {
    ll a, b;
    cin >> a >> b;
    ab[i] = pair<ll,ll>(a,b);
  }

  sort(ab.begin(), ab.end());

  ll ans = 0;
  rep(i,n) {
    if(m - ab[i].second <= 0) {
      ans += ab[i].first * m;
      break;
    }
    ans += ab[i].second * ab[i].first;
    m -= ab[i].second;
  }

  cout << ans << endl;

  return 0;
}
