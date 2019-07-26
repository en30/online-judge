#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)
#define all(a) (a).begin(), (a).end()

int Q;

ll solve(ll a, ll b) {
  ll l = 0, r = 1LL<<31;
  while(r - l > 1) {
    ll m = (l + r) / 2;

    ll res = 0;
    for(ll i = max(m/2-10,1LL); i <= min(m/2+10, m); i++) {
      ll j = i;
      if(a <= i) j++;
      ll k = m + 1 - i;
      if(b <=  m + 1 - i) k++;
      res = max(res, j*k);
    }
    if(res < a*b) {
      l = m;
    } else {
      r = m;
    }
  }
  return l;
}

int main () {
  cin >> Q;

  rep(i,Q) {
    ll A, B;
    cin >> A >> B;

    cout << solve(A, B) << endl;
  }

  return 0;
}
