#include <bits/stdc++.h>
#include "../include/template"

void solve() {
  string s;
  cin >> s;
  int N = s.size();
  int l = -1, r = N;
  rep(i, N) {
    if (l == -1 && s[i] == '1') l = i;
    if (r == N && s[N - 1 - i] == '1') r = N - 1 - i;
  }
  int ans = 0;
  for (int i = l + 1; i < r; ++i)
    if (s[i] == '0') ++ans;
  cout << (ans == N ? 0 : ans) << endl;
}

int main() {
  int t;
  cin >> t;
  rep(i, t) solve();
  return 0;
}
