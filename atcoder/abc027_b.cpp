#include <bits/stdc++.h>
#include "../include/template"

int main() {
  int N;
  cin >> N;
  vector<int> a(N);
  rep(i, N) cin >> a[i];

  int S = accumulate(all(a), 0);
  if (S % N) {
    cout << -1 << endl;
    return 0;
  }

  int ans = 0, s = 0, l = 0;
  rep(i, N) {
    s += a[i];
    ++l;
    if (s == (S / N) * l) {
      ans += l - 1;
      s = 0;
      l = 0;
    }
  }

  cout << (s == 0 ? ans : -1) << endl;
  return 0;
}
