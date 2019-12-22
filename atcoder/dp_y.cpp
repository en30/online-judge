#include <bits/stdc++.h>
#include "../include/template"
#include "../include/mod.hpp"
#include "../include/combination.hpp"

int H, W, N;

struct Wall {
  int r, c;
};
vector<Wall> walls;

int main() {
  cin >> H >> W >> N;
  walls.resize(N + 1);
  rep(i, N) {
    cin >> walls[i].r >> walls[i].c;
    --walls[i].r;
    --walls[i].c;
  }
  walls[N] = Wall{H - 1, W - 1};

  sort(all(walls), [&](const Wall& a, const Wall& b) {
    return a.r == b.r ? a.c < b.c : a.r < b.r;
  });

  Combination<ModInt> comb(H + W - 2);

  auto nRoute = [&](int r, int c) { return comb.C(r + c, r); };

  vector<ModInt> dp(N + 1);
  rep(i, N + 1) {
    dp[i] = nRoute(walls[i].r, walls[i].c);
    rep(j, i) {
      dp[i] -= dp[j] * nRoute(walls[i].r - walls[j].r, walls[i].c - walls[j].c);
    }
  }

  cout << dp[N] << endl;

  return 0;
}
