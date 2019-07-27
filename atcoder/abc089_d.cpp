#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)
#define all(a) (a).begin(), (a).end()

int H, W, D, Q;

struct Point {
  int x, y;
};

map<int, Point> m;

int main () {
  cin >> H >> W >> D;

  rep(i,H) rep(j,W) {
    int A;
    cin >> A;
    A--;
    m[A] = Point{i,j};
  }

  vector<vector<int>> S(D, vector<int>((H*W)/D + 1, 0));
  rep(r,D) {
    for(int i = 0; r + (i+1)*D < H*W; i++) {
      int x = r + i*D;
      S[r][i+1] = S[r][i] + abs(m[x+D].x - m[x].x) + abs(m[x+D].y - m[x].y);
    }
  }

  cin >> Q;
  rep(i,Q) {
    int L, R;
    cin >> L >> R;
    L--, R--;
    int r = L % D;
    cout << S[r][R/D] - S[r][L/D] << endl;
  }

  return 0;
}
