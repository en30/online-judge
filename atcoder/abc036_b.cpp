#include <bits/stdc++.h>
#include "../include/template"

int main() {
  int N;
  cin >> N;
  vector<string> s(N);
  rep(i, N) cin >> s[i];

  vector<string> t(N, string(N, ' '));
  rep(i, N) rep(j, N) t[j][N - 1 - i] = s[i][j];

  rep(i, N) cout << t[i] << endl;

  return 0;
}
