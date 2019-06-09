#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)

int main () {
  int n;
  int T, a;
  cin >> n >> T >> a;

  int ans = 0;
  double m = 1e9;
  rep(i,n) {
    int h;
    cin >> h;
    double t = T - h * 0.006;
    if(abs(t-a) < m) {
      ans = i + 1;
      m = abs(t-a);
    }
  }
  cout << ans << endl;

  return 0;
}
