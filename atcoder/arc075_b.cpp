#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)

ll n,a,b;
int h[100000];

bool enough(ll t) {
  ll c = 0;
  rep(i,n) {
    ll rest = h[i] - t*b;
    if(rest > 0) c += (rest-1)/(a-b) + 1;
  }
  return c <= t;
}

int find(ll lb, ll ub) {
  if(lb == ub) return lb;
  ll m = (lb + ub) / 2;
  return enough(m) ? find(lb, m) : find(m + 1, ub);
}

int main () {
  scanf("%lld%lld%lld", &n, &a, &b);
  rep(i,n) scanf("%d", &h[i]);

  ll l = 0;
  ll r = 1e9+1;
  while(l != r) {
    ll m = (l + r) / 2;
    if(enough(m)) {
      r = m;
    } else {
      l = m + 1;
    }
  }
  printf("%lld\n", l);

  return 0;
}
