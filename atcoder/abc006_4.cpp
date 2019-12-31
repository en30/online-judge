#include <bits/stdc++.h>
#include "../include/template"
#include "../include/lis.hpp"

int N;
vector<int> c;

int main() {
  cin >> N;
  c.resize(N);
  rep(i, N) cin >> c[i];

  cout << N - lis<int>(c, true) << endl;
  return 0;
}
