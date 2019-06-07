#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)

int main () {
  int N, M;
  cin >> N >> M;

  bool m[12][12] = {};

  rep(i,M) {
    int x, y;
    cin >> x >> y;
    m[x-1][y-1] = m[y-1][x-1] = true;
  }

  int ans = 1;
  for(int s = 1 << N; s > 0; s--) {
    int c = bitset<32>(s).count();
    if(c <= ans) continue;

    bool complete = true;
    rep(i,N) {
      for(int j = i+1; j<N; j++) {
        if((s >> i) & (s >> j) & 1 && !m[i][j]) complete = false;
      }
    }

    if(complete) ans = c;
  }

  cout << ans << endl;

  return 0;
}
