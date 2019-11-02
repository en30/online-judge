#include <bits/stdc++.h>
#include "../include/template"

ll N, K;
vector<ll> A, F;

bool achievable(ll m) {
  ll n = 0;
  rep(i, N) n += max(0LL, A[i] - m / F[i]);
  return n <= K;
}

int main() {
  cin >> N >> K;
  A.resize(N), F.resize(N);
  rep(i, N) cin >> A[i];
  rep(i, N) cin >> F[i];

  sort(all(A));
  sort(all(F), greater<ll>());
  assert(A[0] <= A[N - 1]);
  assert(F[0] >= F[N - 1]);

  ll l = -1, r = 1e12;
  while (r - l > 1) {
    ll m = (l + r) / 2;

    if (achievable(m)) {
      r = m;
    } else {
      l = m;
    }
  }

  cout << r << endl;

  return 0;
}
