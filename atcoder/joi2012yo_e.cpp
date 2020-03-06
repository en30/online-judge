#include <bits/stdc++.h>
#include "../include/template"

const vector<int> dx[2] = {{+1, +1, 0, -1, 0, +1}, {+1, 0, -1, -1, -1, 0}};
const vector<int> dy = {0, -1, -1, 0, +1, +1};

struct Position {
  int x, y;
  Position(int x, int y) : x(x), y(y){};
};

int main() {
  int W, H;
  cin >> W >> H;

  auto in = [&](int i, int j) { return 0 <= i && i < W && 0 <= j && j < H; };

  vector<vector<int>> grid(W, vector<int>(H, 0));
  rep(j, H) rep(i, W) cin >> grid[i][j];

  vector<vector<bool>> used(W, vector<bool>(H, false));
  function<void(int, int)> use = [&](int i, int j) {
    queue<Position> q;
    q.emplace(i, j);
    used[i][j] = true;
    while (!q.empty()) {
      auto& p = q.front();
      q.pop();
      rep(d, 6) {
        int ni = p.x + dx[p.y % 2][d], nj = p.y + dy[d];
        if (!in(ni, nj) || used[ni][nj] || grid[ni][nj]) continue;
        q.emplace(ni, nj);
        used[ni][nj] = true;
      }
    }
  };

  function<int(int, int, int)> count = [&](int i, int j, int target) {
    int res = 0;
    queue<Position> q;
    q.emplace(i, j);
    used[i][j] = true;
    while (!q.empty()) {
      auto& p = q.front();
      q.pop();

      int c = 6;
      rep(d, 6) {
        int ni = p.x + dx[p.y % 2][d], nj = p.y + dy[d];
        if (!in(ni, nj)) continue;
        if (grid[ni][nj] == target) c -= 1;
        if (used[ni][nj] || grid[ni][nj] != target) continue;
        q.emplace(ni, nj);
        used[ni][nj] = true;
      }
      res += c;
    }
    return res;
  };

  rep(i, W) {
    if (!used[i][0] && !grid[i][0]) use(i, 0);
    if (!used[i][H - 1] && !grid[i][H - 1]) use(i, H - 1);
  }
  rep(j, H) {
    if (!used[0][j] && !grid[0][j]) use(0, j);
    if (!used[W - 1][j] && !grid[W - 1][j]) use(W - 1, j);
  }

  int ans = 0;
  rep(i, W) rep(j, H) {
    if (!used[i][j] && grid[i][j]) ans += count(i, j, 1);
  }

  rep(i, W) rep(j, H) {
    if (!used[i][j] && !grid[i][j]) ans -= count(i, j, 0);
  }

  cout << ans << endl;

  return 0;
}
