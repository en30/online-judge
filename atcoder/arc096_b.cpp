#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)
#define all(a) (a).begin(), (a).end()

ll N, C;
vector<ll> x, v;

int main () {
  cin >> N >> C;
  x.resize(N), v.resize(N);
  rep(i,N) cin >> x[i] >> v[i];


  ll ans = 0;
  ll y = 0, z = 0;
  vector<ll> r(N+1, 0), l(N+1, 0);
  rep(i,N) {
    y += v[i];
    z += v[N-1-i];
    r[i+1] = max(r[i], y - x[i]);
    l[i+1] = max(l[i], z - (C - x[N-i-1]));
    ans = max(ans, max(r[i+1], l[i+1]));
  }

  y = 0, z = 0;
  rep(i,N) {
    y += v[i];
    z += v[N-1-i];
    ans = max(ans, y - 2*x[i] + l[N-i-1]);
    ans = max(ans, z - 2*(C - x[N-1-i]) + r[N-i-1]);
  }

  cout << ans << endl;

  return 0;
}
