#include <bits/stdc++.h>
#include "../include/template"

int main() {
  int N;
  cin >> N;
  vector<int> a(N);
  rep(i, N) cin >> a[i];

  rep(i, N) {
    if (i != 0) cout << ",";
    cout << a[i];
  }
  cout << endl;
  return 0;
}
