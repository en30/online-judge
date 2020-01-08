#include <bits/stdc++.h>
#include "../include/template"

int N, M;

struct Relic {
  int l, r, s;
};

int main() {
  cin >> N >> M;

  vector<int> L(M + 2, 0), R(M + 2, 0);
  rep(i, N) {
    int l, r, s;
    cin >> l >> r >> s;
    L[r] += s;
    R[l] += s;
  }

  rep(i, M + 1) {
    L[i + 1] += L[i];
    R[M - i] += R[M - i + 1];
  }

  int ans = 0;
  for (int i = 1; i <= M; ++i) {
    ans = max(ans, L[i - 1] + R[i + 1]);
  }

  cout << ans << endl;
  return 0;
}
