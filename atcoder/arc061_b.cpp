#include <bits/stdc++.h>
#include "../include/template"
#include "../include/grid.hpp"

int main() {
  int H, W, N;
  cin >> H >> W >> N;

  using P = pair<int, int>;
  map<P, int> C;
  rep(i, N) {
    int a, b;
    cin >> a >> b;
    --a, --b;
    rep(i, 3) rep(j, 3) {
      if (Grid<int>::in(H, W, a - i, b - j) &&
          Grid<int>::in(H, W, a - i + 2, b - j + 2)) {
        C[make_pair(a - i, b - j)] += 1;
      }
    }
  }

  vector<ll> ans(10, 0);

  for (auto &p : C) ans[p.second] += 1;

  ans[0] = (H - 2LL) * (W - 2LL) - accumulate(ans.begin() + 1, ans.end(), 0LL);
  rep(i, 10) cout << ans[i] << endl;

  return 0;
}
