#include <bits/stdc++.h>
#include "../include/template"

int t, n;
int idx[200001];

void solve() {
  cin >> n;
  rep(i, n) {
    int x;
    cin >> x;
    idx[--x] = i;
  }

  int l = idx[0], r = idx[0];
  rep(i, n) {
    l = min(l, idx[i]);
    r = max(r, idx[i]);
    cout << (r - l == i);
  }

  cout << endl;
}

int main() {
  cin >> t;
  rep(i, t) solve();
  return 0;
}
