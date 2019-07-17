#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)

int N, M;

struct cake {
  ll x,y,z;

  ll val() const {
    return abs(x) + abs(y) + abs(z);
  }

  const cake operator+(const cake& rhs) const {
    return cake{x+rhs.x, y+rhs.y, z+rhs.z};
  }

  bool operator<(const cake& rhs) const {
    return val() < rhs.val();
  }

  int state() {
    int s = 0;
    s += (x >= 0);
    s += (y >= 0) << 1;
    s += (z >= 0) << 2;
    return s;
  }
};

vector<cake> cakes;

vector<cake> dp[1001][1001][8];

int main () {
  cin >> N >> M;
  cakes.resize(N);
  rep(i,N) cin >> cakes[i].x >> cakes[i].y >> cakes[i].z;

  dp[0][0][7].push_back(cake{0,0,0});

  auto maximize = [&](int i, int j, int s, cake &c) {
    if(dp[i][j][s].size() == 0 || dp[i][j][s][0].val() == c.val()) {
      dp[i][j][s].push_back(c);
    } else if(dp[i][j][s].size() != 0 && dp[i][j][s][0].val() < c.val()) {
      dp[i][j][s] = vector<cake>(1,c);
    }
  };

  for(int i = 0; i < N; i++) {
    for(int j = 0; j <= M; j++) {
      for(int s = 0; s < 8; s++) {
        for(cake c: dp[i][j][s]) {
          maximize(i+1, j, s, c);
          if(j == M) continue;
          cake nc = c + cakes[i];
          maximize(i+1, j+1, nc.state(), nc);
        }
      }
    }
  }

  ll ans = 0;
  for(int s = 0; s < 8; s++) {
    for(cake c: dp[N][M][s]) {
      ans = max(ans, c.val());
    }
  }

  cout << ans << endl;

  return 0;
}
