#include <bits/stdc++.h>
#include "../include/template"

int N, K;
vector<int> d;

int main() {
  cin >> N >> K;
  d.resize(N);

  rep(i, N) {
    char c;
    cin >> c;
    d[i] = (c == 'L' ? 0 : 1);
  }

  int ans = 0;
  rep(i, N - 1) {
    if (d[i + 1] == d[i]) ++ans;
  }

  int a = 0, b = 0;
  rep(i, N - 1) {
    if (d[i] == 0 && d[i + 1] == 1) ++a;
    if (d[i] == 1 && d[i + 1] == 0) ++b;
  }

  ans += 2 * min({a, b, K});
  if (K > min(a, b) && a != b) ans += 1;

  cout << ans << endl;
  return 0;
}
