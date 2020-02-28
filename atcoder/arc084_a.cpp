#include <bits/stdc++.h>
#include "../template"

int main() {
  int N;
  cin >> N;
  vector<int> A(N), B(N), C(N);
  rep(i, N) cin >> A[i];
  rep(i, N) cin >> B[i];
  rep(i, N) cin >> C[i];

  sort(all(A));
  sort(all(C));

  ll ans = 0;
  rep(i, N) {
    ll a = distance(A.begin(), lower_bound(all(A), B[i]));
    ll c = distance(upper_bound(all(C), B[i]), C.end());
    ans += a * c;
  }
  cout << ans << endl;

  return 0;
}
