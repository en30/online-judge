#include <bits/stdc++.h>
#include "../include/template"

int main() {
  int N;
  cin >> N;
  vector<int> A(N), B(N);
  rep(i, N) cin >> A[i] >> B[i];

  vector<int> SA(A), SB(B);
  sort(all(SA));
  sort(all(SB));

  int s = SA[N / 2], t = SB[N / 2];
  ll ans = 0;
  rep(i, N) ans += abs(s - A[i]) + B[i] - A[i] + abs(t - B[i]);

  cout << ans << endl;
  return 0;
}
