#include <bits/stdc++.h>
#include "../include/template"

int main() {
  string S;
  cin >> S;

  const int N = S.size();
  int ans = 0;
  rep(i, N - 1) ans += (S[i] != S[i + 1]);
  cout << ans << endl;

  return 0;
}
