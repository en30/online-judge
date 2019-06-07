#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)

int main () {
  int ans = 0, m = 0;

  rep(i,5) {
    int t, l;
    cin >> t;
    l = 10 - (t % 10);
    l %= 10;
    ans += t + l;
    m = max(m, l);
  }
  ans -= m;

  cout << ans << endl;

  return 0;
}
