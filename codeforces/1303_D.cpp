#include <bits/stdc++.h>
#include "../include/template"

const int D = 63;
void solve() {
  ll n;
  int m;
  cin >> n >> m;

  vector<int> c(D, 0);
  rep(i, m) {
    int a;
    cin >> a;
    for (int i = 0; i < D; ++i) {
      if (a == (1 << i)) {
        ++c[i];
        break;
      }
    }
  }

  int ans = 0;
  rep(i, D) {
    bool on = ((n >> i) & 1);
    if (c[i] > 0) {
      if (on) --c[i];
      if (i + 1 < D) c[i + 1] += c[i] / 2;
      continue;
    }
    if (!on) continue;
    int j = i + 1;
    while (j < D && c[j] == 0) ++j;
    if (j == D) {
      cout << -1 << endl;
      return;
    }
    for (int k = j; k > i; --k) {
      --c[k];
      c[k - 1] += 2;
      ++ans;
    }
  }

  cout << ans << endl;
}

int main() {
  int t;
  cin >> t;
  rep(i, t) solve();
  return 0;
}
