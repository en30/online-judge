#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)

int main () {
  int n, m;
  cin >> n >> m;
  vector<int> c(m+1, 0);

  rep(i,n) {
    int k;
    cin >> k;
    rep(j,k) {
      int a;
      cin >> a;
      c[a]++;
    }
  }

  int ans = 0;
  rep(i,m+1) if(c[i] == n) ans++;
  cout << ans << endl;

  return 0;
}
