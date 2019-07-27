#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)
#define all(a) (a).begin(), (a).end()

int A, B;
const int w = 100, h = 100;
int grids[w][h];

int main () {
  cin >> A >> B;

  int nw = 1, nb = 1;
  for(int i = 50; i < w; i++) {
    rep(j,h) grids[i][j] = 1;
  }

  for(int i = 1; i < 50; i += 2) {
    for(int j = 1; j < h; j += 2) {
      if(nb == B) break;
      grids[i][j] = 1;
      nb++;
    }
  }

  for(int i = 51; i < w; i += 2) {
    for(int j = 1; j < h; j += 2) {
      if(nw == A) break;
      grids[i][j] = 0;
      nw++;
    }
  }

  printf("%d %d\n", w, h);
  rep(i,w) {
    rep(j,h) {
      cout << (grids[i][j] ? "#" : ".");
    }
    cout << endl;
  }

  return 0;
}
