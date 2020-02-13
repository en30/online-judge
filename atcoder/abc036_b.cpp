#include <bits/stdc++.h>
#include "../include/template"

int main() {
  int N;
  cin >> N;
  vector<string> s(N);
  rep(i, N) cin >> s[i];
  rep(j, N) {
    rep(i, N) cout << s[N - 1 - i][j];
    cout << endl;
  }

  return 0;
}
