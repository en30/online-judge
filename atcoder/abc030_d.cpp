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

  vector<int> path;
  int c = a;
  vector<bool> used(N + 1, false);
  while (true) {
    used[c] = true;
    path.push_back(c);
    c = b[c];
    if (used[c]) break;
  }
  int r = 0;
  while (path[r] != c) ++r;
  const int T = path.size() - r;
  const int M = k.size();

  if (M <= 6 && stoi(k) <= r) {
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
