#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)

int main () {
  int n;
  cin >> n;
  vector<int> p(n);
  rep(i,n) cin >> p[i];

  sort(p.begin(), p.end());

  int ans = 0;
  rep(i,n) ans += p[i];
  ans -= p[n-1] / 2;
  cout << ans << endl;
  return 0;
}
