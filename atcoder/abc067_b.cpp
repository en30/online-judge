#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)

int main () {
  int n, k;
  cin >> n >> k;
  vector<int> l(n);
  rep(i,n) cin >> l[i];
  sort(l.begin(), l.end(), greater<int>());
  int ans = 0;
  rep(i,k) ans += l[i];
  cout << ans << endl;
  return 0;
}
