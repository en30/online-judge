#include <bits/stdc++.h>
#include "../include/template"

int main() {
  int H, W, N;
  cin >> H >> W >> N;

  map<int, map<int, int>> B;
  rep(i, N) {
    int a, b;
    cin >> a >> b;
    --a, --b;
    B[a][b] = 1;
  }

  vector<ll> ans(10, 0);

  vector<int> di = {0, -1, -2, 0, -1, -2, 0, -1, -2},
              dj = {0, 0, 0, -1, -1, -1, -2, -2, -2};

  auto count = [&](int i, int j, vector<ll> &ans) {
    rep(k, 9) {
      int cnt = 0;
      rep(ii, 3) rep(jj, 3) {
        int r = i + di[k] + ii, c = j + dj[k] + jj;
        if (r < 0 || H <= r || c < 0 || W <= c) goto HOGE;
        if (B.find(r) != B.end() && B[r].find(c) != B[r].end()) cnt += B[r][c];
      }
      ans[cnt] += 1;
    HOGE:;
    }
  };

  for (auto &p : B) {
    int i = p.first;
    for (auto &q : p.second) {
      int j = q.first;
      count(i, j, ans);
    }
  }

  rep(i, 10) if (i) ans[i] /= i;
  ans[0] = (H - 2LL) * (W - 2LL) - accumulate(ans.begin() + 1, ans.end(), 0LL);
  rep(i, 10) cout << ans[i] << endl;

  return 0;
}
