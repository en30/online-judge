#include <bits/stdc++.h>
#include "../include/template"

int N;
vector<vector<int>> a;

int main() {
  cin >> N;
  a.resize(N, vector<int>(N));

  rep(i, N) for (int j = i + 1; j < N; ++j) {
    cin >> a[i][j];
    a[j][i] = a[i][j];
  }

  int ans = -1e9;
  vector<int> G(N);

  auto score = [&]() {
    int s = 0;
    rep(i, N) for (int j = i + 1; j < N; ++j) {
      if (G[i] == G[j]) s += a[i][j];
    }
    return s;
  };

  function<void(int)> search = [&](int i) {
    if (i == N) {
      ans = max(ans, score());
      return;
    }

    rep(g, 3) {
      G[i] = g;
      search(i + 1);
    }
  };

  search(0);

  cout << ans << endl;

  return 0;
}
