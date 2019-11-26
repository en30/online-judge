#include <bits/stdc++.h>
#include "../include/template"

int N, K;
vector<int> A;
int main() {
  cin >> N >> K;

  A.resize(N);
  vector<int> B(N);

  rep(i, N) {
    cin >> A[i];
    B[i] = (A[i] - 1 + K) % K;
  }

  ll ans = 0;

  vector<int> S(N + 1, 0);
  rep(i, N) S[i + 1] = (S[i] + B[i]) % K;

  map<int, vector<int>> m;
  rep(i, N + 1) m[S[i]].push_back(i);

  rep(i, N + 1) {
    auto it = lower_bound(all(m[S[i]]), i);
    auto it2 = lower_bound(all(m[S[i]]), i + K);
    ans += distance(it, it2) - 1;
  }

  cout << ans << endl;
  return 0;
}
