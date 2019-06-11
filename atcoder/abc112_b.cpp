#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)

int main () {
  int N, T;
  cin >> N >> T;

  int ans = 1e5;
  bool tle = true;
  rep(i,N) {
    int c, t;
    cin >> c >> t;
    if(t <= T) {
      tle = false;
      ans = min(ans, c);
    }
  }

  if(tle) {
    cout << "TLE" << endl;
  } else {
    cout << ans << endl;
  }


  return 0;
}
