#include <bits/stdc++.h>
#include "../include/template"
#include "../include/lis.hpp"

int main() {
  int N;
  cin >> N;
  vector<int> a(N);
  rep(i, N) cin >> a[i];

  cout << lis(a, true) << endl;
  return 0;
}
