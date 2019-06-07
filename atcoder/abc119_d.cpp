#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)

const ll INF = 100000000000LL;
int main () {
  int A, B, Q;
  cin >> A >> B >> Q;

  vector<ll> s(A+2), t(B+1);

  s[0] = - INF; t[0] = -INF;
  rep(i,A) cin >> s[i+1];
  rep(i,B) cin >> t[i+1];
  s[A+1] = INF; t[B+1] = INF;

  rep(i,Q) {
    ll x;
    cin >> x;

    vector<ll>::iterator it;
    it = lower_bound(s.begin(), s.end(), x);
    vector<ll> ss = {*it, *(it-1)};

    it = lower_bound(t.begin(), t.end(), x);
    vector<ll> ts = {*it, *(it-1)};

    ll ans = INF;
    for(ll s : ss) {
      for(ll t : ts) {
        ans = min(ans, abs(x-s) + abs(s-t));
        ans = min(ans, abs(x-t) + abs(t-s));
      }
    }

    cout << ans << endl;
  }

  return 0;
}
