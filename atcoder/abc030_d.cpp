#include <bits/stdc++.h>
#include "../include/template"
#include "../include/mod.hpp"

int main() {
  int N, a;
  cin >> N >> a;

  string k;
  cin >> k;
  vector<int> b(N + 1);
  rep(i, N) cin >> b[i + 1];

  vector<int> path(N + 1, a);
  rep(i, N) path[i + 1] = b[path[i]];

  int T = 1;
  while (path[N - T] != path[N]) ++T;
  int r = 0;
  while (path[r] != path[r + T]) ++r;

  const int M = k.size();
  if (M <= 6 && stoi(k) < N) {
    cout << path[stoi(k)] << endl;
    return 0;
  }

  ModInt::mod(T);
  ModInt t = 0;
  rep(i, M) t = t * 10 + (k[i] - '0');
  t -= r;
  cout << path[r + t.val()] << endl;

  return 0;
}
