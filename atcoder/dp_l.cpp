#include <bits/stdc++.h>
#include "../include/template"

int N;
vector<int> a;
vector<vector<ll>> fMemo, gMemo;

ll INIT = 4e12;

ll f(int i, int j);
ll g(int i, int j);

ll f(int i, int j) {
  if (i == j) return a[i];
  if (fMemo[i][j] != INIT) return fMemo[i][j];
  return fMemo[i][j] = max(a[i] + g(i + 1, j), a[j] + g(i, j - 1));
}

ll g(int i, int j) {
  if (i == j) return -a[i];
  if (gMemo[i][j] != INIT) return gMemo[i][j];
  return gMemo[i][j] = min(-a[i] + f(i + 1, j), -a[j] + f(i, j - 1));
}

int main() {
  cin >> N;
  a.resize(N);
  fMemo.resize(N, vector<ll>(N, INIT));
  gMemo.resize(N, vector<ll>(N, INIT));
  rep(i, N) cin >> a[i];

  cout << f(0, N - 1) << endl;
  return 0;
}
