#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i, N) for (int i = 0; i < (int)N; i++)

ll calc(ll s, ll w, ll h) {
  if(w % 2 == 0 || h % 2 == 0) {
    return abs(s - (ll(h*w)) /2);
  } else {
    ll diff = min(h,w);
    ll s2 = (h*w + diff) / 2;
    ll s3 = (h*w - diff) / 2;
    return max(max(abs(s - s2), abs(s - s3)), abs(s2 - s3));
  }
}

int main () {
  ll H, W;
  cin >> H >> W;
  ll res = H*W;
  REP(i,H) res = min(res, calc(i*W, W, H - i));
  REP(i,W) res = min(res, calc(i*H, W - i, H));
  cout << res << endl;
  return 0;
}
