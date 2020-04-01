#include <bits/stdc++.h>
#include "../include/template"

const int R = 26;
void solve() {
  int n, k;
  scanf("%d %d", &n, &k);
  string s;
  cin >> s;

  int ans = 0;
  rep(i, (k + 1) / 2) {
    vector<int> c(R, 0);
    rep(j, n / k) {
      ++c[s[j * k + i] - 'a'];
      if (k - 1 - i != i) ++c[s[j * k + k - 1 - i] - 'a'];
    }
    ans += accumulate(all(c), 0) - (*max_element(all(c)));
  }
  printf("%d\n", ans);
}

int main() {
  int t;
  cin >> t;
  rep(i, t) solve();
  return 0;
}
