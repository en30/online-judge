#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)

int K;

int S(ll N) {
  if(N < 10) return N;
  return (N % 10) + S(N/10);
}

ll f(ll N) {
  vector<pair<double,ll>> res;
  for(ll m = 1; m <= N*10; m *= 10) {
    ll k = m*(N/m + 1) - 1;
    res.push_back(pair<double,ll>((double)k/S(k), k));
  }
  sort(res.begin(), res.end());
  return res[0].second;
}

int main () {
  cin >> K;

  ll N = 1;
  rep(i,K) {
    printf("%lld\n", N);
    N = f(N+1);
  }
  return 0;
}
