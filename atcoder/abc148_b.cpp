#include <bits/stdc++.h>
#include "../include/template"

int N;
string S, T;
int main() {
  cin >> N >> S >> T;
  string ans = "";
  rep(i, N) { ans = ans + S[i] + T[i]; }

  cout << ans << endl;

  return 0;
}
