#include <bits/stdc++.h>
#include "../include/template"

int N, K;

int main() {
  cin >> N >> K;
  vector<int> V(N);
  rep(i, N) cin >> V[i];

  ll ans = 0;
  for (int l = 1; l <= K; ++l) {
    for (int k = min(l, N); k >= l - k; --k) {
      for (int i = 0; i <= k; ++i) {
        priority_queue<ll, vector<ll>, greater<ll>> pq;
        rep(j, i) pq.push(V[j]);
        rep(j, k - i) pq.push(V[N - 1 - j]);

        rep(j, l - k) if (pq.top() < 0) pq.pop();

        ll s = 0;
        while (!pq.empty()) {
          s += pq.top();
          pq.pop();
        }
        ans = max(ans, s);
      }
    }
  }

  cout << ans << endl;

  return 0;
}
