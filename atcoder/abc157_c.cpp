#include <bits/stdc++.h>
#include "../include/template"

int main() {
  int N, M;
  cin >> N >> M;

  vector<int> s(M);
  vector<char> c(M);
  rep(i, M) {
    cin >> s[i] >> c[i];
    --s[i];
  }

  int MAX = 1;
  rep(i, N) MAX *= 10;

  auto ok = [&](int n) {
    string t = to_string(n);
    if (t.size() != N) return false;
    rep(i, M) if (t[s[i]] != c[i]) return false;
    return true;
  };

  for (int i = 0; i < MAX; ++i) {
    if (ok(i)) {
      cout << i << endl;
      return 0;
    }
  }

  cout << -1 << endl;
  return 0;
}
