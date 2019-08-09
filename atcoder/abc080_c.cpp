#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)
#define all(a) (a).begin(), (a).end()

int N;
vector<bitset<10>> F;
vector<vector<int>> P;

int main () {
  cin >> N;

  F.resize(N);
  P.resize(N, vector<int>(11));

  rep(i,N) rep(j,5) rep(k,2) {
    int f;
    cin >> f;
    if(f) F[i].set(j*2+k);
  }
  rep(i,N) rep(c,11) {
    cin >> P[i][c];
  }

  ll ans = -1e9;
  for(int s = 1; s < (1<<10); s++) {
    auto j = bitset<10>(s);
    ll p = 0;
    rep(i,N) {
      p += P[i][(F[i] & j).count()];
    }
    ans = max(ans, p);
  }

  cout << ans << endl;

  return 0;
}
