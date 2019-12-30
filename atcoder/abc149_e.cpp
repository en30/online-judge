#include <bits/stdc++.h>
#include "../include/template"
#include "../include/convolution.hpp"

int N;
ll M;
vector<int> A;
const int SUM_MAX = 2e5;

int main() {
  cin >> N >> M;
  A.resize(N);
  rep(i, N) cin >> A[i];

  vector<ll> freq(SUM_MAX + 1, 0);
  rep(i, N) freq[A[i]] += 1;

  Convolution<ll> conv(freq, freq);
  ll ans = 0;
  for (int i = SUM_MAX; i >= 0; --i) {
    ll c = min(M, conv[i]);
    ans += c * i;
    M -= c;
    if (M == 0) break;
  }
  cout << ans << endl;

  return 0;
}
