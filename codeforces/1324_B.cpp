#include <bits/stdc++.h>
#include "../include/template"

vector<int> a(5000);

void solve() {
  int n;
  scanf("%d", &n);
  rep(i, n) scanf("%d", &a[i]);
  rep(i, n - 2) {
    for (int j = i + 2; j < n; ++j) {
      if (a[i] == a[j]) {
        cout << "YES" << endl;
        return;
      }
    }
  }
  cout << "NO" << endl;
}

int main() {
  int t;
  cin >> t;
  rep(i, t) solve();
  return 0;
}
