#include <bits/stdc++.h>
#include "../include/template"

struct Machine {
  int x, y;
};

int W, H;
int N;
vector<Machine> M;
using square = tuple<int, int, int, int>;
map<square, ll> memo;

ll search(int x0, int y0, int x1, int y1) {
  square s(x0, y0, x1, y1);
  if (memo.find(s) != memo.end()) return memo[s];

  ll res = 0;
  ll c = (x1 - x0 + 1) + (y1 - y0 + 1) - 1;
  for (Machine &m : M) {
    if (x0 <= m.x && m.x <= x1 && y0 <= m.y && m.y <= y1) {
      res = max(res, c + search(x0, y0, m.x - 1, m.y - 1) +
                         search(x0, m.y + 1, m.x - 1, y1) +
                         search(m.x + 1, y0, x1, m.y - 1) +
                         search(m.x + 1, m.y + 1, x1, y1));
    }
  }

  return memo[s] = res;
}

int main() {
  cin >> W >> H;
  cin >> N;

  M.resize(N);

  rep(i, N) cin >> M[i].x >> M[i].y;

  cout << search(1, 1, W, H) << endl;

  return 0;
}
