#include <bits/stdc++.h>
#include "../include/template"

ll K;
vector<ll> a;
int main() {
  cin >> K;

  if (K == 0) {
    cout << 2 << endl;
    cout << "0 0" << endl;
    return 0;
  }

  ll N = min(K + 1, 50LL);
  ll rest = K;
  ll c = (K - N + 1 + N) / (N + 1);
  a.resize(N, N - 1 + (N + 1) * c - K);
  rest -= c * N;

  rep(i, N) {
    if (rest == 0) break;
    ll d = min((10000000000001000LL - a[i]) / (N + 1), rest);
    a[i] += (N + 1) * d;
    rest -= d;
  }

  cout << N << endl;
  rep(i, N) {
    if (i != 0) cout << " ";
    cout << a[i];
  }
  cout << endl;
  return 0;
}
