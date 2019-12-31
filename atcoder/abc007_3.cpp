#include <bits/stdc++.h>
#include "../include/template"

int R, C;
int sy, sx, gy, gx;
vector<string> c;

struct Point {
  int y, x;
};

int main() {
  cin >> R >> C;
  cin >> sy >> sx;
  cin >> gy >> gx;
  --sy, --sx, --gy, --gx;
  c.resize(R);
  rep(i, R) cin >> c[i];

  queue<Point> q;
  q.push(Point{sy, sx});
  vector<vector<int>> d(R, vector<int>(C, -1));
  vector<int> dy = {1, 0, -1, 0};
  vector<int> dx = {0, 1, 0, -1};
  d[sy][sx] = 0;
  while (!q.empty()) {
    auto p = q.front();
    q.pop();
    rep(i, 4) {
      int ny = p.y + dy[i], nx = p.x + dx[i];
      if (c[ny][nx] == '.' && d[ny][nx] == -1) {
        d[ny][nx] = d[p.y][p.x] + 1;
        q.push(Point{ny, nx});
      }
    }
  }

  cout << d[gy][gx] << endl;

  return 0;
}
