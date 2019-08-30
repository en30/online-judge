#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)
#define all(a) (a).begin(), (a).end()

int N;
vector<int> t, v;

int main () {
  cin >> N;
  t.resize(N);
  v.resize(N+1, 0);
  rep(i,N) {
    cin >> t[i];
    t[i] *= 2;
  }
  rep(i,N) {
    cin >> v[i];
    v[i] *= 2;
  }

  vector<int> d(N+1, 0);
  rep(i,N) d[i+1] = d[i] + t[i];
  rep(i,N+1) d[i] += v[i];
  for(int i = N - 1; i >= 0; i--) {
    d[i] = min(d[i], d[i+1]);
  }

  double x = 0;
  int vc = 0;
  int tc = 0;
  rep(i,N) {
    int tb = tc;
    rep(j,t[i]) {
      if(vc >= - tc + d[i+1]) {
        x += vc - 0.5;
        vc -= 1;
      } else if(vc >= v[i]) {
        x += vc;
      } else {
        x += vc + 0.5;
        vc += 1;
      }
      tc += 1;
    }
  }

  printf("%.4lf\n", x*0.25);
  return 0;
}
