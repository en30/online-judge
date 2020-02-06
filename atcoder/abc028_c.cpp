#include <bits/stdc++.h>
#include "../include/template"

int main() {
  vector<int> a(5), v;
  rep(i, 5) cin >> a[i];
  cout << max(a[0] + a[3] + a[4], a[1] + a[2] + a[4]) << endl;
  return 0;
}
