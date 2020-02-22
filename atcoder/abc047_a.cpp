#include <bits/stdc++.h>
#include "../include/template"

int main() {
  vector<int> a(3);
  rep(i, 3) cin >> a[i];

  sort(all(a));
  cout << (a[0] + a[1] == a[2] ? "Yes" : "No") << endl;
  return 0;
}
