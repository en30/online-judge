#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)

int main () {
  int D, G;
  cin >> D >> G;
  G /= 100;
  vector<int> p(D), c(D);
  rep(i,D) {
    cin >> p[i] >> c[i];
    c[i] /= 100;
  }

  int ans = 1000;

  for(int i = 0; i < (1<<D); i++) {
    int s = 0;
    int cnt = 0;
    for(int j = 0; j < D; j++) {
      if((i >> j) & 1) {
        s += (j+1)*p[j] + c[j];
        cnt += p[j];
      }
    }
    for(int j = D - 1; s < G && j >= 0; j--){
      if((i >> j) & 1) continue;
      int k = (G - s + (j+1) - 1) / (j+1);
      k = min(k, p[j]);
      s += k * (j+1);
      cnt += k;
    }

    if(s >= G) ans = min(ans, cnt);
  }

  cout << ans << endl;

  return 0;
}
