#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)
#define all(a) (a).begin(), (a).end()

int H, W;
vector<string> S;

vector<vector<int>> dirs = {
  {1, 0}, {1, 1}, {0, 1}, {-1, 1}, {-1, 0}, {-1, -1}, {0, -1}, {1, -1}
};

int main () {
  cin >> H >> W;
  S.resize(H);
  rep(i,H) cin >> S[i];

  rep(i,H) {
    rep(j,W) {
      if(S[i][j] == '.') {
        int c = 0;
        for(auto dx: dirs) {
          int ni = i + dx[0];
          int nj = j + dx[1];
          if(ni < 0 || ni >= H || nj < 0 || nj >= W) continue;
          if(S[ni][nj] == '#') c++;
        }
        cout << c;
      } else {
        cout << S[i][j];
      }
    }
    cout << endl;
  }
  return 0;
}
