#include <bits/stdc++.h>
#include "../include/template"

int N;
vector<ll> A;

int main() {
  cin >> N;
  A.resize(N);
  rep(i, N) cin >> A[i];

  const int D = 60;
  ll allXor = 0;
  rep(i, N) allXor ^= A[i];
  rep(i, N) A[i] &= ~allXor;

  int idx = 0;
  for (int d = D - 1; d >= 0; --d) {
    int j = idx;
    while (j < N && (((A[j] >> d) & 1) == 0)) ++j;
    if (j < N) {
      swap(A[idx], A[j]);
      rep(k, N) {
        if (k != idx && ((A[k] >> d) & 1)) {
          A[k] ^= A[idx];
        }
      }
      ++idx;
    }
  }

  ll ans = 0;
  rep(i, N) ans = max(ans, ans ^ A[i]);
  ans <<= 1;
  ans += allXor;

  cout << ans << endl;

  return 0;
}
