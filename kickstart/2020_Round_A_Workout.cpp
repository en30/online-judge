#include <bits/stdc++.h>
#include "../include/template"

int solve() {
  int N, K;
  cin >> N >> K;
  vector<int> M(N);
  rep(i, N) cin >> M[i];

  auto achievable = [&](int m) {
    if (m == 0) return false;

    int k = 0;
    rep(i, N - 1) k += (M[i + 1] - M[i] - 1) / m;
    return k <= K;
  };

  int l = 0, r = 1e9;
  while (r - l > 1) {
    int m = (l + r) / 2;
    if (achievable(m)) {
      r = m;
    } else {
      l = m;
    }
  }

  return r;
}

int main() {
  int T;
  cin >> T;
  rep(i, T) cout << "Case #" << i + 1 << ": " << solve() << endl;
  return 0;
}
