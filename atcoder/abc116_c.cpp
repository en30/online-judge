#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)

int main () {
  int n;
  cin >> n;
  vector<int> h(n);
  rep(i,n) cin >> h[i];

  int ans = 0;
  for(int i = 1; i <= 100; i++) {
    bool streak = false;
    rep(j,n) {
      if(h[j] >= i) {
        if(!streak) ans++;
        streak = true;
      } else {
        streak = false;
      }
    }
  }

  cout << ans << endl;
  return 0;
}
