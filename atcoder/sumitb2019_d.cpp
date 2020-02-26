#include <bits/stdc++.h>
#include "../include/template"

int main() {
  int N;
  cin >> N;
  string S;
  cin >> S;

  int ans = 0;
  rep(i, 10) rep(j, 10) rep(k, 10) {
    vector<char> c = {i + '0', j + '0', k + '0'};
    int m = -1;
    rep(l, 3) {
      ++m;
      while (m < N && S[m] != c[l]) ++m;
    }
    ans += (m < N);
  };
  cout << ans << endl;

  return 0;
}
