#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)
#define all(a) (a).begin(), (a).end()

ll X, Y;

int main () {
  cin >> X >> Y;

  int ans = 0;
  while(X <= Y) {
    X *= 2LL;
    ans++;
  }

  cout << ans << endl;
  return 0;
}
