#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)

int main () {
  int n, m;
  cin >> n >> m;
  vector<int> x(m);
  rep(i,m) cin >> x[i];

  sort(x.begin(), x.end());

  vector<int> diff(m-1);
  rep(i,m-1) {
    diff[i] = x[i+1] - x[i];
  }
  sort(diff.begin(), diff.end(), greater<int>());

  int ans = x[m-1] - x[0];
  rep(i,n-1) {
    if(i < m - 1) ans -= diff[i];
  }
  cout << ans << endl;

  return 0;
}
