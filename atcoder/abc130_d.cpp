#include <bits/stdc++.h>
#include "../include/template"

ll N, K;
vector<ll> a;
int main() {
  cin >> N >> K;
  a.resize(N);
  rep(i, N) cin >> a[i];

  ll ans = 0;
  int k = 0;
  ll sum = 0;
  rep(i, N) {
    while (k < N && sum < K) sum += a[k++];
    if (sum < K) break;
    ans += N - k + 1;
    sum -= a[i];
  }

  cout << ans << endl;
  return 0;
}
