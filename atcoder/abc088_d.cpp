#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)
#define all(a) (a).begin(), (a).end()

const int INF = 1e9;
struct P {
  int x, y;
};

int H, W;
vector<vector<char>> s;
vector<vector<int>> d;
vector<P> dir = {P{1,0}, P{-1,0}, P{0,1}, P{0,-1}};

int main () {
  cin >> H >> W;
  s.resize(H, vector<char>(W));
  d.resize(H, vector<int>(W, INF));

  int nb = 0;
  rep(i,H)rep(j,W) {
    cin >> s[i][j];
    if(s[i][j] == '#') nb++;
  }

  d[0][0] = 0;
  queue<P> q;
  q.push(P{0,0});
  while(!q.empty()) {
    P p = q.front();
    q.pop();
    for(auto dr: dir) {
      int nx = p.x + dr.x;
      int ny = p.y + dr.y;
      if(0 <= nx && nx < W && 0 <= ny && ny < H && s[ny][nx] != '#' && d[ny][nx] == INF) {
        d[ny][nx] = d[p.y][p.x] + 1;
        q.push(P{nx,ny});
      }
    }
  }

  if(d[H-1][W-1] == INF) {
    cout << -1 << endl;
  } else {
    cout << W*H - 2 - nb - (d[H-1][W-1] - 1) << endl;
  }

  return 0;
}
