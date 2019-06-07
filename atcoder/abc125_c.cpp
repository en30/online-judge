#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)

int gcd(int a, int b) {
  if(a < b) return gcd(b, a);
  if(b == 0) return a;
  return gcd(b, a % b);
}

int main () {
  int n;
  cin >> n;
  vector<int> a(n);

  int aMin = 1e9 + 1;
  rep(i,n) cin >> a[i];

  vector<int> l(n), r(n);
  l[0] = 0;
  r[n-1] = 0;

  for(int i = 1; i < n; i++) {
    l[i] = gcd(a[i-1], l[i-1]);
    r[n-1-i] = gcd(a[n-i], r[n-i]);
  }

  int ans = 1;
  rep(i,n) ans = max(ans, gcd(l[i], r[i]));

  cout << ans << endl;

  return 0;
}
