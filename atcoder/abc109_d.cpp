#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)

struct mov {
  int y, x, yp, xp;
};

int main () {
  int H, W;
  cin >> H >> W;
  vector<vector<int>> a(H, vector<int>(W));
  rep(i,H)rep(j,W) {
    cin >> a[i][j];
    a[i][j] &= 1;
  }

  vector<mov> ans;

  rep(i,H) {
    bool moving = false;
    rep(j,W) {
      if(moving) ans.push_back(mov{i,j-1,i,j});
      if(a[i][j]) moving = !moving;
    }
    if(moving && i < H - 1) {
      a[i+1][W-1] += 1;
      a[i+1][W-1] &= 1;
      ans.push_back(mov{i,W-1,i+1,W-1});
    }
  }

  cout << ans.size() << endl;
  for(mov m: ans) printf("%d %d %d %d\n", m.y+1, m.x+1, m.yp+1, m.xp+1);

  return 0;
}
