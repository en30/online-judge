#include <bits/stdc++.h>
#include "../include/template"

int main() {
  vector<int> a(3);
  rep(i, 3) cin >> a[i];
  sort(all(a));
  if (a[0] == 5 && a[1] == 5 && a[2] == 7) {
    cout << "YES";
  } else {
    cout << "NO";
  }
  cout << endl;

  return 0;
}
