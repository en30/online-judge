#include <bits/stdc++.h>
#include "../include/template"

int main() {
  vector<int> d1(2), d2(2);
  rep(i, 2) cin >> d1[i];
  rep(i, 2) cin >> d2[i];
  rep(i, 2) rep(j, 2) {
    if (d1[i] == d2[j]) {
      cout << "YES" << endl;
      return 0;
    }
  }
  cout << "NO" << endl;

  return 0;
}
