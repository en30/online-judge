#include <bits/stdc++.h>
#include "../include/template"

ll N, M, V, P;

int main() {
  cin >> N >> M >> V >> P;
  vector<int> A(N);
  rep(i, N) cin >> A[i];

  sort(all(A));

  vector<ll> S(N + 1, 0);
  rep(i, N) S[i + 1] = S[i] + A[i];

  int l = 0, m = 0, r = 0;
  rep(i, N) {
    ll s = A[i] + M;
    ll rest = M * V;
    while (r < N - P + 1 && A[r] <= s) ++r;
    if (N - r > P - 1) continue;
    while (A[l] + M < s) ++l;
    while (m < r && A[m] < s) ++m;

    rest -= (N - r) * M;
    rest -= l * M;
    rest -= (m - l) * s - (S[m] - S[l]);
    if (rest <= 0) {
      cout << N - i << endl;
      return 0;
    }
  }

  return 0;
}
