#include <bits/stdc++.h>
#include "../include/template"

int N;
vector<int> a;
int main() {
  cin >> N;
  a.resize(N);
  rep(i, N) cin >> a[i];

  int c = 1;

  rep(i, N) if (a[i] == c)++ c;

  cout << (c == 1 ? -1 : N - c + 1) << endl;

  return 0;
}
