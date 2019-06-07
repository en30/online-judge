#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i, N) for (int i = 0; i < (int)N; i++)

int main () {
  ll a,b, ans;
  cin >> a >> b;

  if(a == b) {
    cout << 1 << endl;
    return 0;
  }

  int r = 60;
  ll one = 1;
  while((a & (one << (r-1))) == (b & (one << (r-1)))) r--;

  a &= (one << r) - 1;
  b &= (one << r) - 1;

  ans = (one << r) - a;

  int k = r - 1;
  while(k > 0 && !(b & (one << (k-1)))) k--;

  if(a > (one << k)) ans -= a - (one << k);

  cout << ans << endl;
  return 0;
}
