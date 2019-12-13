#include <bits/stdc++.h>
#include "../include/template"

int N, X;
vector<int> L;

int main() {
  cin >> N >> X;
  L.resize(N);
  rep(i, N) cin >> L[i];

  int D = 0;
  int ans = 1;
  rep(i, N) {
    D += L[i];
    if (D <= X) ++ans;
  }

  cout << ans << endl;

  return 0;
}
