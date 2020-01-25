#include <bits/stdc++.h>
#include "../include/template"

int N, D, K;

int main() {
  cin >> N >> D >> K;
  vector<int> L(D), R(D), S(K), T(K), ans(K, -1);
  rep(i, D) cin >> L[i] >> R[i];
  rep(i, K) cin >> S[i] >> T[i];

  rep(i, D) {
    rep(j, K) {
      if (ans[j] != -1) continue;

      if (L[i] <= S[j] && S[j] <= R[i]) {
        if (S[j] < T[j]) {
          S[j] = R[i];
          if (S[j] >= T[j]) ans[j] = i + 1;
        } else {
          S[j] = L[i];
          if (S[j] <= T[j]) ans[j] = i + 1;
        }
      }
    }
  }

  rep(i, K) cout << ans[i] << endl;
  return 0;
}
