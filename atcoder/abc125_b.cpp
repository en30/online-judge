#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)

int main () {
  int n;

  cin >> n;


  vector<int> v(n), c(n);

  rep(i,n) cin >> v[i];
  rep(i,n) cin >> c[i];

  int ans = 0;
  rep(i,n) if(v[i] > c[i]) ans += v[i] - c[i];

  cout << ans << endl;
  return 0;
}
