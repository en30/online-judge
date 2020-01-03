#include <bits/stdc++.h>
#include "../include/template"

int main() {
  vector<int> a(6);
  rep(i, 6) cin >> a[i];
  sort(all(a));
  cout << a[3] << endl;

  return 0;
}
