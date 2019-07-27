#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)
#define all(a) (a).begin(), (a).end()

int N;
vector<int> a, b;

int main () {
  cin >> N;
  a.resize(N), b.resize(N);

  rep(i,N) cin >> a[i];
  rep(i,N) cin >> b[i];

  const int D = 29;
  vector<vector<int>> pb(D, vector<int>(N));
  for(int d = 0; d < D; d++) {
    rep(i,N) pb[d][i] = b[i] % (1 << (d+1));
    sort(all(pb[d]));
  }

  int ans = 0;
  for(int d = 0; d < D; d++) {
    int c = 0;
    rep(i,N) {
      int ar = a[i] % (1<<(d+1));
      c += distance(lower_bound(all(pb[d]), (1<<d) - ar), lower_bound(all(pb[d]), (1<<(d+1)) - ar));
      c &= 1;
      c += distance(lower_bound(all(pb[d]), 3*(1<<d) - ar), lower_bound(all(pb[d]), (1<<(d+2)) - ar));
      c &= 1;
    }
    if(c) ans |= (1<<d);
  }

  cout << ans << endl;

  return 0;
}
