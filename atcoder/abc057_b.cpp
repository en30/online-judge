#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)

int main () {
  int n, m;
  cin >> n >> m;
  vector<int> a(n), b(n), c(m), d(m);
  rep(i,n) cin >> a[i] >> b[i];
  rep(i,m) cin >> c[i] >> d[i];
  rep(i,n) {
    int k = 0, mind = 1e9;
    rep(j,m) {
      int md = abs(a[i] - c[j]) + abs(b[i] - d[j]);
      if(md < mind) {
        mind = md;
        k = j;
      }
    }
    cout << k + 1 << endl;
  }
  return 0;
}
