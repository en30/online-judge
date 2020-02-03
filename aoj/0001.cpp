#include <bits/stdc++.h>
#include "../include/template"

int main() {
  vector<int> h(10);
  rep(i, 10) cin >> h[i];
  sort(all(h));
  cout << h[9] << endl;
  cout << h[8] << endl;
  cout << h[7] << endl;
  return 0;
}
