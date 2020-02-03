#include <bits/stdc++.h>
#include "../include/template"

int main() {
  int N;
  cin >> N;
  vector<int> l(3);

  rep(i, N) {
    rep(i, 3) cin >> l[i];
    sort(all(l));
    cout << (l[0] * l[0] + l[1] * l[1] == l[2] * l[2] ? "YES" : "NO") << endl;
  }

  return 0;
}
