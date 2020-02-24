#include <bits/stdc++.h>
#include "../include/template"

bool solve() {
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  rep(i, n) cin >> a[i];
  vector<bool> swappable(n - 1, false);
  rep(i, m) {
    int p;
    cin >> p;
    --p;
    swappable[p] = true;
  }

  rep(i, n - 1) for (int j = 0; j < n - i - 1; ++j) {
    if (a[j] > a[j + 1]) {
      if (!swappable[j]) return false;
      swap(a[j], a[j + 1]);
    }
  }
  return true;
}

int main() {
  int t;
  cin >> t;
  rep(i, t) cout << (solve() ? "YES" : "NO") << endl;

  return 0;
}
