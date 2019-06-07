#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)

int gcd(int a, int b) {
  if(b == 0) return a;
  return gcd(b, a % b);
}

ll c(int n, int k) {
  vector<int> u(k), d(k);
  rep(i,k) {
    u[i] = n - k + i + 1;
    d[i] = i + 1;
  }
  rep(i,k) {
    rep(j,k) {
      if(u[j] == 1 || d[i] == 1) continue;
      int c = gcd(u[j], d[i]);
      u[j] /= c;
      d[i] /= c;
    }
  }
  ll ans = 1;
  rep(i,k) ans *= u[i];
  return ans;
}

int main () {
  int n, a, b;
  cin >> n >> a >> b;
  vector<ll> v(n);
  rep(i,n) cin >> v[i];

  sort(v.begin(), v.end(), greater<ll>());

  double m = 0;
  rep(i,a) {
    m += (double) v[i] / a;
  }
  printf("%lf\n", m);

  int k = 0;
  for(int i = a-1; i >= 0; i--) {
    if(v[a-1] != v[i]) break;
    k++;
  }

  int l = 0;
  for(int i = a; i < n; i++) {
    if(v[a-1] != v[i]) break;
    l++;
  }

  ll ans = 0;
  if(k == a) {
    for(int i = k, m = min(k+l, b-a+k); i <= m; i++) {
      ans += c(k+l, i);
    }
  } else {
    ans = c(k+l, k);
  }
  printf("%lld\n", ans);
  return 0;
}
