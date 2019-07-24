#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)
#define all(a) (a).begin(), (a).end()

int H, W;
vector<vector<int>> s;

vector<vector<int>> moves = {{1,0}, {0,1}, {-1, 0}, {0,-1}};

bool paintable(int i, int j) {
  s[i][j] = 0;
  bool res = false;
  for(auto d: moves) {
    int ni = i + d[0], nj = j + d[1];
    if(ni >= 0 && ni < H && nj >= 0 && nj < W && s[ni][nj]) {
      res = true;
      paintable(ni, nj);
    }
  }
  return res;
}

int main () {
  cin >> H >> W;
  s.resize(H, vector<int>(W));

  rep(i,H)rep(j,W) {
    char c;
    cin >> c;
    s[i][j] = (c == '#') ;
  }


  rep(i,H)rep(j,W) {
    if(s[i][j] && !paintable(i,j)) {
      cout << "No" << endl;
      return 0;
    }
  }

  cout << "Yes" << endl;
  return 0;
}
