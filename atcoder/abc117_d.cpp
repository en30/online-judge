#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)


ll n, k;
vector<bitset<64>> b;
bitset<64> kb;
vector<int> kflag;
vector<ll> ones;

ll solve(int d, int ki) {
  ll det = 0;
  while(d > kflag[ki]) {
    det += (1LL<<d) * (kb[d] ? n - ones[d] : ones[d]);
    d--;
  }
  if(d < 0) return det;

  // 0
  ll res = 0;
  res = (1LL<<d) * ones[d];
  rep(i,d) res += (1LL<<i) * max(ones[i], n - ones[i]);
  return det + max(res, solve(d, ki+1));
}

int main () {
  cin >> n >> k;

  b = vector<bitset<64>>(n);
  kb = bitset<64>(k);
  for(int i = 63; i > 0; i--) if(kb[i]) kflag.push_back(i);
  kflag.push_back(-1);

  rep(i,n) {
    ll a;
    cin >> a;
    b[i] = bitset<64>(a);
  }

  ll ans = 0;
  ones = vector<ll>(64, 0);
  rep(i,64) {
    rep(j,n) {
      if(b[j][i]) ones[i]++;
    }
  }

  cout << solve(63, 0) << endl;

  return 0;
}
