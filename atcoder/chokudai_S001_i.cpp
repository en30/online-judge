#include <bits/stdc++.h>
#include "../include/template"

int main() {
  int N;
  cin >> N;
  vector<int> a(N);
  rep(i, N) cin >> a[i];

  // s = sum([l, r])
  int l = 0, s = 0, ans = 0;
  rep(r, N) {
    s += a[r];
    while (s >= N) {
      if (s == N) ++ans;
      s -= a[l++];
    }
  }

  cout << ans << endl;
  return 0;
}
