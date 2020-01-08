#include <bits/stdc++.h>
#include "../include/template"

int N, M;

struct Relic {
  int l, r, s;
};

int main() {
  cin >> N >> M;

  vector<int> S(M + 1, 0);

  vector<int> L(M + 2, 0), R(M + 2, 0);
  int sum = 0;
  rep(i, N) {
    int l, r, s;
    cin >> l >> r >> s;
    S[l] += s;
    S[r + 1] -= s;
    sum += s;
  }

  rep(i, M) S[i + 1] += S[i];

  int ans = 0;
  for (int i = 1; i <= M; ++i) {
    ans = max(ans, sum - S[i]);
  }

  cout << ans << endl;
  return 0;
}
