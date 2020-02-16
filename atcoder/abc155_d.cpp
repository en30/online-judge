#include <bits/stdc++.h>
#include "../include/template"

int main() {
  int N;
  ll K;
  cin >> N >> K;
  vector<ll> A;

  int nZero = 0;
  rep(i, N) {
    ll e;
    cin >> e;
    if (e == 0) {
      ++nZero;
    } else {
      A.push_back(e);
    }
  }
  sort(all(A));

  int M = A.size();

  function<ll(ll)> pairLTE = [&](ll m) {
    ll res = 0;
    int zeroI = distance(A.begin(), lower_bound(all(A), 0));
    if (m < 0) {
      int r = zeroI;
      rep(i, zeroI) {
        while (r < M && A[i] * A[r] > m) ++r;
        res += M - r;
      }
    } else {
      for (int l = zeroI, r = M - 1; l < M; ++l) {
        while (r > l && A[l] * A[r] > m) --r;
        if (r >= l) res += r - l;
      }
      for (int r = zeroI - 1, l = 0; r >= 0; --r) {
        while (r > l && A[l] * A[r] > m) ++l;
        if (r >= l) res += r - l;
      }
      res += ll(M) * nZero + ll(nZero) * (nZero - 1) / 2 + pairLTE(-1LL);
    }
    return res;
  };

  ll l = -1e18 - 1, r = 1e18;
  while (r - l > 1) {
    ll m = (l + r) / 2;
    if (pairLTE(m) < K) {
      l = m;
    } else {
      r = m;
    }
  }
  cout << r << endl;

  return 0;
}
